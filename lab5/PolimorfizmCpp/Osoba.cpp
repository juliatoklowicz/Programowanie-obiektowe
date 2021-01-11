#include <iostream>
#include <string>
#include <ctime>
#include "Osoba.h"

using namespace std;

Osoba::Osoba()
{
    this->imie = nullptr;
    this->nazwisko = nullptr;
}

Osoba::Osoba(Osoba &osoba)
{
    this->imie = new string;
    *this->imie = "";
    this->nazwisko = new string;
    *this->nazwisko = "";
}

Osoba::Osoba(Osoba &&osoba)
{
    this->imie = osoba.imie;
    osoba.imie = nullptr;
    this->nazwisko = osoba.nazwisko;
    osoba.nazwisko = nullptr;
}

Osoba::Osoba(string x)
{
    this->imie = new string;
    *this->imie = x;
    this->nazwisko = nullptr;
}

void Osoba::ustaw_nazwisko()
{
    if (this->imie == nullptr)
    {
        this->imie = new string;
        this->nazwisko = new string;
    }
    cout << "Podaj imie osoby: ";
    cin >> *this->imie;
    cout << "Podaj nazwsiko osoby: ";
    cin >> *this->nazwisko;
}

void Osoba::odczytaj_nazwisko()
{
    if (this->imie == nullptr)
    {
        this->imie = new string;
        this->nazwisko = new string;
    }
    cout << "Imie: " << *this->imie << endl;
    cout << "Nazwisko: " << *this->nazwisko << endl; 
}

void Osoba::ustaw_date()
{
    time_t t = time(0);
    tm * now = localtime(&t);
    cout << "Podaj rok urodzenia: ";
    cin >> data_urodzenia.rok;
    cout << "Podaj miesiac urodzenia: ";
    cin >> data_urodzenia.miesiac;
    cout << "Podaj dzien urodzenia: ";
    cin >> data_urodzenia.dzien;
    while ((data_urodzenia.rok > now->tm_year + 1900) || (data_urodzenia.rok == now->tm_year + 1900  && data_urodzenia.miesiac > now->tm_mon + 1) || (data_urodzenia.rok == now->tm_year + 1900 && data_urodzenia.miesiac == now->tm_mon + 1 && data_urodzenia.dzien > now->tm_mday))
        {
            cout << "Podales niepoprawna date!" << endl;
            cout << "Podaj rok urodzenia: ";
            cin >> data_urodzenia.rok;
            cout << "Podaj miesiac urodzenia: ";
            cin >> data_urodzenia.miesiac;
            cout << "Podaj dzien urodzenia: ";
            cin >> data_urodzenia.dzien;
        }
}

void Osoba::odczytaj_date()
{
    cout << "Data urodzenia: " << data_urodzenia.dzien << "." << data_urodzenia.miesiac << "." << data_urodzenia.rok << endl;
}

void Osoba::ustaw_adres()
{
    cout << "Podaj adres zamieszkania" << endl;
    cout << "Ulica: ";
    cin >> adres.ulica;
    cout << "Numer domu: ";
    cin >> adres.numer;
    cout << "Miasto: ";
    cin >> adres.miasto;
    cout << "Kod pocztowy: ";
    cin >> adres.kod_pocztowy;
}

void Osoba::odczytaj_adres()
{
    cout << "Adres zamieszkania: " << endl;
    cout << "ul." << adres.ulica << " " << adres.numer << endl;
    cout << adres.kod_pocztowy << " " << adres.miasto << endl;
}

void Osoba::przedstaw()
{
    if (this->imie == nullptr)
    {
        this->imie = new string;
        this->nazwisko = new string;
    }
    cout << "Imie: " << *this->imie << endl;
    cout << "Nazwisko: " << *this->nazwisko << endl; 
    cout << "Data urodzenia: " << data_urodzenia.dzien << "." << data_urodzenia.miesiac << "." << data_urodzenia.rok << endl;
    cout << "Adres zamieszkania: " << endl;
    cout << "ul." << adres.ulica << " " << adres.numer << endl;
    cout << adres.kod_pocztowy << " " << adres.miasto << endl;
}

Osoba::~Osoba()
{
    delete imie;
    delete nazwisko;
}