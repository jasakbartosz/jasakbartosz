#include <iostream>
#include <windows.h>
  #include <conio.h>
     
using namespace std;
 
double pobierz(int liczba){
       while(!(cin>>liczba)){
            cout << "Podaj poprawna wartosc: ";
  cin.clear(); 
  cin.sync();}
  return liczba;
       }
 
int main() {
      start:
    system("title SoundSkan");
  cout << "SoundSkan by Jasiek65"  << endl;
    cout << "Sprawdz do jakiej czestotliwosci slyszysz!" << endl;
  cout << "--------------------------------------------------------------------------" << endl;
    int min, max;
    int interwal;
   
    cout << "Podaj czestotliwosc minimalna: ";
  min = pobierz(min);
  cout << "Podaj czestotliowsc maksymalna: ";
  max = pobierz(max);
  cout << "Podaj interwal(odstep): ";
  interwal = pobierz(interwal);
   
system("color 02");
    for(int a=min; a<max; a= a+interwal)
    {
    
             cout<< "Aktualna czestotliwosc: "<< a << endl;
              Beep(a,200);
              system("cls");
             }
     
     
    cout << "Wytrzymales? Zakonczyc? T/N";
    char znak;
    znak = getch();  
    if(znak != 't')
    {
    system("cls");
        goto start;  
            }
 return 0;   
}