#ifndef OSOBA_H
#define OSOBA_H

#include <string>

using namespace std;

struct Data
{
    int dzien;
    int miesiac;
    int rok;
};

class Adres
{
public:
    string ulica;
    int numer;
    string miasto;
    int kod_pocztowy;
};

class Osoba
{
private:
    string *imie;
    string *nazwisko;
    Adres adres;
    Data data_urodzenia;
public:
    Osoba();
    Osoba(Osoba &osoba);
    Osoba(Osoba &&osoba);
    Osoba(string x);
    virtual ~Osoba();
    void ustaw_nazwisko();
    void odczytaj_nazwisko();
    void ustaw_date();
    void odczytaj_date();
    void ustaw_adres();
    void odczytaj_adres();
    virtual void przedstaw();
};

#endif