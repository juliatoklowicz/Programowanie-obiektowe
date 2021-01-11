#include <iostream>
#include <string>
#include <vector>
#include "Pracownik.h"
#include "Osoba.h"

using namespace std;

Pracownik::Pracownik() : Osoba() //konstruktor domyslny
{
    
}

Pracownik::Pracownik(Pracownik &pracownik) : Osoba(pracownik) //konstruktor kopiujacy
{
    
}

Pracownik::Pracownik(Pracownik &&pracownik) : Osoba(pracownik) //konstruktor przenoszacy
{
    
}

Pracownik::Pracownik(string x) //konstruktor konwertujacy
{
    przedmioty.push_back(x);
}

void Pracownik::lista_przedmiotow()
{
    cout << "Lista przedmiotow prowadzonych przez danego pracownika: " << endl;
    for (int i = 0; i < przedmioty.size(); i++)
    {
        cout << przedmioty[i] << endl;
    }
}

void Pracownik::dodaj_przedmiot()
{
    string s;
    cout << "Wpisz nazwe przedmiotu, ktory chcesz dodac: ";
    cin >> s;
    bool x = false;
    for (int i = 0; i < przedmioty.size(); i++)
    {
        if (przedmioty[i] == s)
        {
            x = true;
        }
    }
    if (x)
    {
        cout << "Dany przedmiot jest juz prowadzony przez pracownika" << endl;
    }
    else
    {
       przedmioty.push_back(s);
    }
}

void Pracownik::usun_przedmiot()
{
    string s;
    cout << "Wpisz nazwe przedmiotu, ktory chcesz usunac: ";
    cin >> s;
    bool x = false;
    int a;
    for (int i = 0; i < przedmioty.size(); i++)
    {
        if (przedmioty[i] == s)
        {
            x = true;
            a = i;
        }
    }
    if (x)
    {
        przedmioty.erase(przedmioty.begin()+a);
    }
    else
    {
        cout << "Dany przedmiot nie znajduje sie na liscie przedmiotow pracownika" << endl;
    }
}

void Pracownik::czy_prowadzi()
{
    string s;
    cout << "Wprowadz nazwe przedmiotu, ktorego szukasz: ";
    cin >> s;
    bool x = false;
    for (int i = 0; i < przedmioty.size(); i++)
    {
        if (przedmioty[i] == s)
        {
            x = true;
        }
    }
    if(x)
    {
        cout << "Pracownik prowadzi ten przedmiot" << endl;
    }
    else
    {
        cout << "Pracownik nie prowadzi tego przemdiotu" << endl;
    }
}

void Pracownik::przedstaw()
{
    Osoba::przedstaw();
    cout << "Lista przedmiotow prowadzonych przez danego pracownika: " << endl;
    for (int i = 0; i < przedmioty.size(); i++)
    {
        cout << przedmioty[i] << endl;
    }
}

Pracownik::~Pracownik()
{
    
}