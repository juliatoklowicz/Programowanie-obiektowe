#include <iostream>
#include <ctime>
#include "RadaNadzorcza.h"
#include "Logger.h"
#include "Stopper.h"

using namespace std;

RadaNadzorcza::RadaNadzorcza() //konstruktor domyslny
{
    Reset();
    this->liczba_czlonkow = nullptr;
    this->srednia_uchwal = nullptr;
    this->budzet = nullptr;
    this->rok = nullptr;
    this->miesiac = nullptr;
    this->dzien = nullptr;
    this->liczba_kobiet = nullptr;
}

RadaNadzorcza::RadaNadzorcza(RadaNadzorcza &rada) //konstruktor kopiujacy
{
    Reset();
    this->liczba_czlonkow = new int;
    *this->liczba_czlonkow = 0;
    this->srednia_uchwal = new int;
    *this->srednia_uchwal = 0;
    this->budzet = new float;
    *this->budzet = 0;
    this->rok = new int;
    *this->rok = 0;
    this->miesiac = new int;
    *this->miesiac = 0;
    this->dzien = new int;
    *this->dzien = 0;
    this->liczba_kobiet = new int;
    *this->liczba_kobiet = 0;
}



RadaNadzorcza::RadaNadzorcza(RadaNadzorcza &&rada) //konstruktor przenoszacy
{
    Reset();
    this->liczba_czlonkow = rada.liczba_czlonkow;
    this->srednia_uchwal = rada.srednia_uchwal;
    this->budzet = rada.budzet;
    this->rok = rada.rok;
    this->miesiac = rada.miesiac;
    this->dzien = rada.dzien;
    this->liczba_kobiet = rada.liczba_kobiet;

    rada.liczba_czlonkow = nullptr;
    rada.srednia_uchwal = nullptr;
    rada.budzet = nullptr;
    rada.rok = nullptr;
    rada.miesiac = nullptr;
    rada.dzien = nullptr;
    rada.liczba_kobiet = nullptr;

}

RadaNadzorcza::RadaNadzorcza(int x) //konstruktor konwertujacy
{
    Reset();
    this->liczba_czlonkow = new int;
    *this->liczba_czlonkow = x;
    this->srednia_uchwal = nullptr;
    this->budzet = nullptr;
    this->rok = nullptr;
    this->miesiac = nullptr;
    this->dzien = nullptr;
    this->liczba_kobiet = nullptr;
}


void RadaNadzorcza::liczba_powolanych()
{
    Start();
    if (this->liczba_czlonkow == nullptr)
    {
        this->liczba_czlonkow = new int;
        *this->liczba_czlonkow = 0;
    }
    int l1;
    cout << "Podaj liczbe czlonkow powolanych przez walne zgromadzenie: ";
    cin >> l1;
    *(this->liczba_czlonkow) += l1;
    Stop();
}

void RadaNadzorcza::liczba_odwolanych()
{
    Start();
    if (this->liczba_czlonkow == nullptr)
    {
        this->liczba_czlonkow = new int;
        *this->liczba_czlonkow = 0;
    }
    int l2;
    cout << "Podaj liczbe czlonkow odwolanych przez walne zgromadzenie: ";
    cin >> l2;
    while (*(this->liczba_czlonkow) < l2)
    {
        cout << "Liczba czlonkow nie moze spasc ponizej 0!" << endl;
        cout << "Podaj prawidlowa liczbe czlonkow odwolanych przez walne zgromadzenie: ";
        cin >> l2;
        
    }
    *(this->liczba_czlonkow) -= l2;
    Stop();
}

void RadaNadzorcza::aktualna_liczba()
{
    Start();
    if (this->liczba_czlonkow == nullptr)
    {
        this->liczba_czlonkow = new int;
        *this->liczba_czlonkow = 0;
    }
    cout << "Aktualna liczba czlonkow rady nadzorczej wynosi: " << *(this->liczba_czlonkow) << endl;
    Stop();
}


void RadaNadzorcza::uchwaly_poprzedni_rok()
{
    Start();
    if (this->srednia_uchwal == nullptr)
    {
        this->srednia_uchwal = new int;
        *this->srednia_uchwal = 0;
    }
    int x,y;
    int suma = 0;
    cout << "Podaj liczbe uchwal wydanych w poprzednim roku: ";
    cin >> x;
    int tab[10] = {60,30,18,20,38,38,19,20,28,x};
    for (int i = 0; i < 10; i++)
    {
        suma = suma + tab[i];
    }
    y = suma/10;
    *this->srednia_uchwal = y;
    Stop();
}

void RadaNadzorcza::aktualna_srednia()
{
    Start();
    if (this->srednia_uchwal == nullptr)
    {
        this->srednia_uchwal = new int;
        *this->srednia_uchwal = 0;
    }
    cout << "Aktualna srednia liczba wydanych w poprzednim roku uchwal: " << *this->srednia_uchwal << endl;
    Stop();
}

void RadaNadzorcza::wplywy()
{
    Start();
    if (this->budzet == nullptr)
    {
        this->budzet = new float;
        *this->budzet = 0;
    }
    float wplyw;
    cout << "Podaj wartosc wplywu do budzetu: ";
    cin >> wplyw;
    *this->budzet = *this->budzet + wplyw;
    Stop();
}

void RadaNadzorcza::wydatki()
{
    Start();
    if (this->budzet == nullptr)
    {
        this->budzet = new float;
        *this->budzet = 0;
    }
    float wydatek;
    cout << "Podaj wysokosc wydatkow: ";
    cin >> wydatek;
    *this->budzet = *this->budzet - wydatek;
    Stop();
}

void RadaNadzorcza::aktualny_budzet()
{
    Start();
    if (this->budzet == nullptr)
    {
        this->budzet = new float;
        *this->budzet = 0;
    }
    cout << "Aktualny budzet: " << *this->budzet << endl;
    Stop();
}

void RadaNadzorcza::data_planowana()
{
    Start();
    if (this->rok == nullptr)
    {
        this->rok = new int;
        *this->rok = 0;
        this->miesiac = new int;
        *this->miesiac = 0;
        this->dzien = new int;
        *this->dzien = 0;
    }
    time_t t = time(0);
    tm * now = localtime(&t);
    if(*this->rok > now->tm_year + 1900)
    {
        cout << "Nie mozna ustawic nowej daty, poniewaz aktualne planowane posiedzenie jeszcze sie nie odbylo" << endl;
    }
    else if (*this->rok == now->tm_year + 1900 && *this->miesiac > now->tm_mon + 1)
    {
        cout << "Nie mozna ustawic nowej daty, poniewaz aktualne planowane posiedzenie jeszcze sie nie odbylo" << endl;
    }
    else if(*this->rok == now->tm_year + 1900 && *this->miesiac == now->tm_mon + 1 && *this->dzien > now->tm_mday)
    {
        cout << "Nie mozna ustawic nowej daty, poniewaz aktualne planowane posiedzenie jeszcze sie nie odbylo" << endl;
    }
    else
    {
        cout << "Podaj rok planowanego zgromadzenia rady: ";
        cin >> *this->rok;
        cout << "Podaj miesiac planowanego zgromadzenia rady: ";
        cin >> *this->miesiac;
        cout << "Podaj dzien planowanego posiedzenia rady: ";
        cin >> *this->dzien;
        while ((*this->rok < now->tm_year + 1900) || (*this->rok == now->tm_year + 1900  && *this->miesiac < now->tm_mon + 1) || (*this->rok == now->tm_year + 1900 && *this->miesiac == now->tm_mon + 1 && *this->dzien < now->tm_mday))
        {
            cout << "Podales niepoprawna date!" << endl;
            cout << "Podaj rok planowanego zgromadzenia rady: ";
            cin >> *this->rok;
            cout << "Podaj miesiac planowanego zgromadzenia rady: ";
            cin >> *this->miesiac;
            cout << "Podaj dzien planowanego posiedzenia rady: ";
            cin >> *this->dzien;
        }
    }
    Stop();
}

void RadaNadzorcza::ostatnia_data()
{
    Start();
    if (this->rok == nullptr)
    {
        this->rok = new int;
        *this->rok = 0;
        this->miesiac = new int;
        *this->miesiac = 0;
        this->dzien = new int;
        *this->dzien = 0;
    }
    cout << "Data ostatniego zgromadzenia: " << *this->dzien << "." << *this->miesiac << "." << *this->rok << endl;
    Stop();
}

void RadaNadzorcza::liczba_kobiet1()
{
    Start();
    if (this->liczba_kobiet == nullptr)
    {
        this->liczba_kobiet= new int;
        *this->liczba_kobiet = 0;
    }
    int lk;
    cout << "Podaj aktualna liczbe kobiet w zarzadzie: ";
    cin >> lk;
    *this->liczba_kobiet = lk;
    Stop();
}

void RadaNadzorcza::liczba_kobiet2()
{
    Start();
    if (this->liczba_kobiet == nullptr)
    {
        this->liczba_kobiet= new int;
        *this->liczba_kobiet = 0;
    }
    cout << "Aktualna liczba kobiet w zarzadzie: " << *this->liczba_kobiet << endl;
    Stop();
}

void RadaNadzorcza::liczba_mezczyzn()
{
    Start();
    if (this->liczba_kobiet == nullptr)
    {
        this->liczba_kobiet= new int;
        *this->liczba_kobiet = 0;
    }
    if (this->liczba_czlonkow == nullptr)
    {
        this->liczba_czlonkow= new int;
        *this->liczba_czlonkow = 0;
    }
    cout << "Aktualna liczba mezczyzn w zarzadzie: " << *this->liczba_czlonkow - *this->liczba_kobiet << endl;
    Stop();
}


RadaNadzorcza::~RadaNadzorcza() //destruktor
{
    delete liczba_czlonkow;
    delete srednia_uchwal;
    delete budzet;
    delete rok;
    delete miesiac;
    delete dzien;
    delete liczba_kobiet;
}