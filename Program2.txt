#include <iostream>
 
int main()
{
 
    using namespace std;
int waga, wzrost;
float bmi;
 
 
      
cout << "Podaj swoj wzrost(cm): ";
cin >> wzrost;
 
while(wzrost < 40 or wzrost > 300)
{
   cout << "Wzrost nieprawidlowy: Podaj ponownie: ";
   cin >> wzrost;
}
 
cout << "Podaj swoja wage(kg): ";
cin >> waga;
 
while(waga < 30 or waga > 500)
{
   cout << "Waga nieprawidlowa: Podaj ponownie: ";
   cin >> waga;
}
 
bmi = waga / (wzrost*wzrost/10000.); 
 
cout << "Twoje BMI wynosi:" << endl;
cout << bmi << endl << endl;
 
 
if(bmi < 15)
{
cout << "Jestes patyczakiem! Musisz duzo jesc." << endl;
}
 
if(bmi < 18 and bmi > 15)
{
cout << "Masz niedowage! Skorzystaj z bardziej tluszczowej diety." << endl;
}
 
if(bmi > 18 and bmi < 25)
{
cout << "Twoje BMI jest idealne!" << endl;
}
 
if(bmi > 25 and bmi < 30)
{
cout << "Masz nadwage! Skorzystaj z diety ograniczajacej zawartosc tluszczu." << endl;
}
 
if(bmi > 30 and bmi < 35)
{
cout << "Jestes otyly! Zrzuc pare kilo i bedzie ok." << endl;
}
if(bmi > 35)
{
cout << "Twoje BMI jest \"idealne!\" Radzilbym jednak przejsc na diete, zawierajaca duzo owocow. " << endl;
}
getchar(); getchar();
 
return 0;
}