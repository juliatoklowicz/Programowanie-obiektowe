#ifndef RADANADZORCZA_H
#define RADANADZORCZA_H

#include "Logger.h"
#include "Stopper.h"

class RadaNadzorcza : public Logger , public Stopper
{
private:
    int *liczba_czlonkow;
    int *srednia_uchwal;
    float *budzet;
    int *rok;
    int *miesiac;
    int *dzien;
    int *liczba_kobiet;

public:
    RadaNadzorcza();
    RadaNadzorcza(RadaNadzorcza &rada);
    RadaNadzorcza(RadaNadzorcza &&rada);
    RadaNadzorcza(int x);
    ~RadaNadzorcza();
    void wyzeruj();
    void liczba_powolanych();
    void liczba_odwolanych();
    void aktualna_liczba();
    void uchwaly_poprzedni_rok();
    void aktualna_srednia();
    void wplywy();
    void wydatki();
    void aktualny_budzet();
    void data_planowana();
    void ostatnia_data();
    void liczba_kobiet1();
    void liczba_kobiet2();
    void liczba_mezczyzn();
};

#endif