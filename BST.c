#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



typedef struct el{
    char imie[16];
    char nazwisko[16];
    long numer1;
    long numer2;
    struct el* left;
    struct el* right;
    struct el* up;
    }element;
    
void ClrScr(); //wywo³ana czyœci zawartoœæ ekranu
element* create(element* up); //tworzy nowy element drzewa, mo¿na podaæ mu adres jego ojca, zwraca swój adres;
void printelement(element* druk); //wypisuje dane elementu na ekran, podaæ wskaŸnik na strukturê jako dane
int compare(char wyraz1[16],char wyraz2[16]);//porównuje dwa napisy, zwraca -1 gdy pierwszy mniejszy, 0 gdy równe, 1 gdy drugi mniejszy
void insert(element* nowy,element*root);//umieszcza dany element, zaczynaj¹c od korzenia (root)
void minimum(element* wezel);//wyszukuje element minimalny zaczynaj¹c od podanego wêz³a, koniec gdy nie ma nic po lewej
void maximum(element* wezel);//wyszukuje element maksymakny zaczynaj¹c od podanego wêz³a, koniec gdy nie ma nic po prawej
void InOrder(element* root);//przejœcie InOrder po drzewie, jako argument dostaje korzeñ
int search(element* root,char input[16]);//szuka nazwiska input zaczynaj¹c od korzenia root, zwraca 0 jeœli znajdzie
int licz(element* root);//sumuje rekurencyjnie ilosc elementów ca³ego drzewa, koñcowo zwraca iloœæ wêz³ów
int wysokosc(element* root);//oblicza wysokoœæ drzewa rekurencyjnie, koñcowo zwraca d³ugoœæ najwy¿szej ga³êzi

void ClrScr()
{
  //Dla linuxa:
  //printf("\033[2J"); // Czyœci ekran
  //printf("\033[0;0f"); // Ustawia kursor w lewym, górnym rogu
  //Dla windowsa:
  system("cls");
}

element* create(element* up)
{
element* nowy=malloc(sizeof(element));
int wybor=0;
if(nowy==NULL) return NULL;
(*nowy).up=up;
(*nowy).left=NULL;
(*nowy).right=NULL;
printf("Podaj imie: ");
	fgets((*nowy).imie,16,stdin);
	fflush(stdin);
printf("Podaj nazwisko: ");
	fgets((*nowy).nazwisko,16,stdin);
	fflush(stdin);
printf("Podaj pierwszy numer telefonu: ");
	scanf("%ld",&(*nowy).numer1);
	fflush(stdin);
printf("Czy chcesz podac drugi numer telefonu? (1-Tak,0-Nie): ");
	scanf("%d",&wybor);
	fflush(stdin);
if(wybor==1)
{
	printf("Podaj drugi numer telefonu: ");
	scanf("%ld",&(*nowy).numer2);
	fflush(stdin);
}
else (*nowy).numer2=0;
return nowy;
}

void printelement(element* druk)
{
printf("Imie:     %s",(*druk).imie);
printf("Nazwisko: %s",(*druk).nazwisko);
printf("Numer 1:  %ld",(*druk).numer1);
if((*druk).numer2!=0) printf("\nNumer 2:  %ld\n",(*druk).numer2);
else printf("\n");
}

int compare(char input1[16],char input2[16])
{
int i,wynik;
char wyraz1[16];
char wyraz2[16];
for(i=0; i<16; i++)
	{
	wyraz1[i]=tolower(input1[i]);
	wyraz2[i]=tolower(input2[i]);
	if(wyraz1[i]=='\n') wyraz1[i]='\0';
	if(wyraz2[i]=='\n') wyraz2[i]='\0';
	}
wynik=strcmp(wyraz1,wyraz2);
return wynik;
}

void insert(element* nowy, element* root)
{
element* wezel=root;
int dzialanie;
int koniec=1;
do{
dzialanie=compare((*nowy).nazwisko,(*wezel).nazwisko);
if(dzialanie==0);
{
	dzialanie=compare((*nowy).imie,(*wezel).imie);
}
if(dzialanie<=0)
{
	if((*wezel).left==NULL)
	{
		(*wezel).left=nowy;
		(*nowy).up=wezel;
		koniec=0;		
	}
	else
	{
		wezel=(*wezel).left;	
	}
}
if(dzialanie>0)
{
	if((*wezel).right==NULL)
	{
		(*wezel).right=nowy;
		(*nowy).up=wezel;
		koniec=0;
	}
	else
	{
		wezel=(*wezel).right;
	}
}
}while(koniec!=0);
}

void minimum(element* wezel)
{
	if((*wezel).left==NULL)
	{
		printelement(wezel);
		return;
	}
	else
	{
	minimum((*wezel).left);
	}
}

void maximum(element* wezel)
{
	if((*wezel).right==NULL)
	{
		printelement(wezel);
		return;
	}
	else
	{
		maximum((*wezel).right);
	}
}

void InOrder(element* root)
{
if(root==NULL) return;
InOrder((*root).left);
printelement(root);
printf("-------------------\n");
InOrder((*root).right);
return;
}

int search(element* root,char input[16])
{
element* wsk=root;
int wynik=1;
int end=0;
do{
	if(wsk==NULL) 
	{
		end=1;
	}
	else
	{	
	wynik=compare(input,(*wsk).nazwisko);
	if(wynik==0) end=1;
	if(wynik<0)
	{
		wsk=(*wsk).left;
	}
	if(wynik>0)
	{
		wsk=(*wsk).right;
	}
	}
}while(end!=1);
return wynik;
}

int licz(element* root)
{
if(root==NULL) return 0;
else
{
	int iloscl=licz((*root).left);
	int iloscp=licz((*root).right);
	return iloscl+iloscp+1;
}
}

int wysokosc(element* root)
{
if(root==NULL) return 0;
else
{
	int wysokoscl=wysokosc((*root).left);
	int wysokoscp=wysokosc((*root).right);
	if(wysokoscl>wysokoscp) return (wysokoscl+1);
	else return (wysokoscp+1);
   }
}


main()
{
int wybor,ilosc=0,wynik;
element* root;
element* nowy;
char nazwisko[16];
do{
wynik=0;
ClrScr();
printf("Prosta ksiazka telefoniczna. Aktualna liczba elementow to: %d\nDostepne dzialania:\n",ilosc);
printf(" 1 - wprowadzanie nowego elementu\n 2 - przejscie po drzewie inOrder\n 3 - wyszukanie wartosci minmalnej\n 4 - wyszukanie wartosci maksymalnej\n 5 - zliczanie liczby elementow drzewa\n 6 - wyszukanie po nazwisku\n 7 - okreslenie wysokosci drzewa\n");
printf(" 0 - konczy prace programu\nTwoj wybor: ");
	scanf("%d",&wybor);
	fflush(stdin);
if(ilosc==0)
{
	if(wybor>1)
	{
		printf("Musisz najpierw wprowadzic pierwsza osobe!\n");
		wybor=1;
	}
}
switch(wybor){
	case 1:
		if(ilosc==0) 
		{
			root=create(NULL);
			ilosc++;
		}
		else
		{
			nowy=create(NULL);
			insert(nowy,root);
			ilosc++;
		}
		break;
	case 2:
		InOrder(root);
		getchar();
		break;
	case 3:
		minimum(root);
		getchar();
		break;
	case 4:
		maximum(root);
		getchar();
		break;
	case 5:
		wynik=licz(root);
		printf("Aktualna liczba elementow to: %d", wynik);
		getchar();
		break;
	case 6:
		printf("Podaj szukane nazwisko: ");
			fgets(nazwisko,16,stdin);
			getchar();
		wynik=search(root,nazwisko);
		if(wynik==0) printf("Osoba o podanym nazwisku istnieje.\n");
		else printf("Osoba o podanym nazwisku nie istnieje.\n");
		getchar();
		break;
	case 7:
		wynik=wysokosc(root);
		printf("Wysokosc drzewa to %d wêz³y. ",wynik);
		getchar();
		break;
	case 0:
		printf("Do widzenia!");
		break;
}
}while(wybor!=0);
}





