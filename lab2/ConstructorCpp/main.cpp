#include <iostream>
#include <ctime>
#include "RadaNadzorcza.h"
#include "Logger.h"
#include "Stopper.h"

using namespace std;

void foo(RadaNadzorcza rada)
{
    rada.aktualna_liczba();
}
//mozna uzyc konstruktora kopiujacego lub w przypadku semantyki move konstruktora przenoszacego
//ale nie mozna uzyc konstruktora przeksztalcajacego

void bar(RadaNadzorcza &rada)
{
    rada.aktualna_liczba();
}
//nie mozna uzyc konstruktora kopiujacego ani semantyki move, poniewaz przekazujemy do funkcji referencje do pamieci
//w ktorej obiekt jest zapisany

void qux(RadaNadzorcza &&rada)
{
    rada.aktualna_liczba();
}
//mozemy skorzystac z semantyki move, ktora tworzy L wartosc, natomiast konstruktor przeksztalcajacy tworzy R wartosc

int main()
{
    int x;
    RadaNadzorcza rada;
    cout << "Menu:" << endl;
    cout << "1.Wprowadz liczbe czlonkow powolanych przez walne zgromadzenie." << endl;
    cout << "2.Wprowadz liczbe czlonkow odwolanych przez walne zgromadzenie." << endl;
    cout << "3.Sprawdz aktualna liczbe czlonkow rady nadzorczej." << endl;
    cout << "4.Wprowadz liczbe uchwal wydanych w poprzednim roku." << endl;
    cout << "5.Sprawdz aktualna srednia liczbe wydanych w zeszlym roku uchwal." << endl;
    cout << "6.Wprowadz wplyw do budzetu." << endl;
    cout << "7.Wprowadz wydatki z budzetu." << endl;
    cout << "8.Sprawdz aktualny budzet." << endl;
    cout << "9.Dodaj date nastepnego planowanego zgromadzenia rady." << endl; 
    cout << "10.Sprawdz date nastepnego zgromadzenia." << endl;
    cout << "11.Wprowadz aktualna liczbe kobiet w radzie." << endl;
    cout << "12.Sprawdz aktualna liczbe kobiet w radzie." << endl;
    cout << "13.Sprawdz aktualna liczbe mezczyzn w radzie." << endl;
    cout << "14.Zakoncz." << endl;
    while (x != 14)
    {
        cout << "Wprowadz liczbe od 1 do 14: ";
        cin >> x;
        switch(x)
        {
            case 1:
                rada.liczba_powolanych();
                break;
            case 2:
                rada.liczba_odwolanych();
                break;
            case 3:
                rada.aktualna_liczba();
                break;
            case 4:
                rada.uchwaly_poprzedni_rok();
                break;
            case 5:
                rada.aktualna_srednia();
                break;
            case 6:
                rada.wplywy();
                break;
            case 7:
                rada.wydatki();
                break;
            case 8:
                rada.aktualny_budzet();
                break;
            case 9:
                rada.data_planowana();
                break;
            case 10:
                rada.ostatnia_data();
                break;
            case 11:
                rada.liczba_kobiet1();
                break;
            case 12:
                rada.liczba_kobiet2();
                break;
            case 13:
                rada.liczba_mezczyzn();
                break;
            case 14:
                break;
            default:
                cout << "Niepoprawna liczba" << endl;
                break;

        }
    }
    rada.log("abc");
    //26. Funckja log jest public oraz dziedziczenie rowniez public, dlatego mozna wywolac funckje log z poziomu funkcji main
    //29. Aby program sie kompilowal, trzeba bylo utworzyc konstruktor domyslny dla klasy Logger
    //32. Najwieksze ryzyko dziedziczenia z 2 klas to powtarzanie sie nazw np. zmiennych
    //w Javie mozna skorzystac z keyword implements, ktory umozliwa wielokrotne dziedziczenie 
    return 0;
}