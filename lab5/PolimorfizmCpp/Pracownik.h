#ifndef PRACOWNIK_H
#define PRACOWNIK_H

#include <vector>
#include <string>
#include "Osoba.h"

using namespace std;

class Pracownik : public Osoba
{
private:
    vector <string> przedmioty;
public:
    Pracownik();
    Pracownik(Pracownik &pracownik);
    Pracownik(Pracownik &&pracownik);
    Pracownik(string x);
    ~Pracownik();
    void lista_przedmiotow();
    void dodaj_przedmiot();
    void usun_przedmiot();
    void czy_prowadzi();
    void przedstaw();
};
#endif