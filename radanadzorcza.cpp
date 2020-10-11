#include <iostream>
#include <ctime>

using namespace std;

struct Data
{
    int rok;
    int miesiac;
    int dzien;
};

class RadaNadzorcza
{
    public:
    int liczba_czlonkow;
    int srednia_uchwal;
    float budzet;
    Data data;
    int liczba_kobiet;

    int liczba_powolanych(RadaNadzorcza rada)
    {
        int l1;
        cout << "Podaj liczbe czlonkow powolanych przez walne zgromadzenie: ";
        cin >> l1;
        rada.liczba_czlonkow = rada.liczba_czlonkow + l1;
        return rada.liczba_czlonkow;
    }

    int liczba_odwolanych(RadaNadzorcza rada)
    {
        int l2;
        cout << "Podaj liczbe czlonkow odwolanych przez walne zgromadzenie: ";
        cin >> l2;
        while (l2 > rada.liczba_czlonkow)
        {
            cout << "Liczba czlonkow nie moze spasc ponizej 0!" << endl;
            cout << "Podaj prawidlowa liczbe czlonkow odwolanych przez walne zgromadzenie: ";
            cin >> l2;
        }
        rada.liczba_czlonkow = rada.liczba_czlonkow - l2;
        return rada.liczba_czlonkow;
    }

    void aktualna_liczba(RadaNadzorcza rada)
    {
        cout << "Aktualna liczba czlonkow rady nadzorczej wynosi: " << rada.liczba_czlonkow << endl;
    }

    int uchwaly_poprzedni_rok(RadaNadzorcza rada)
    {
        int x,y;
        cout << "Podaj liczbe uchwal wydanych w poprzednim roku: ";
        cin >> x;
        cout << "Podaj liczbe uchwal wydanych w biezacym roku: ";
        cin >> y;
        return (x+y)/2;
    }

    void aktualna_srednia(RadaNadzorcza rada)
    {
        cout << "Aktualna srednia liczba wydanych uchwal: " << rada.srednia_uchwal << endl;
    }

    float wplywy(RadaNadzorcza rada)
    {
        float wplyw;
        cout << "Podaj wartosc wplywu do budzetu: ";
        cin >> wplyw;
        rada.budzet = rada.budzet + wplyw;
        return rada.budzet;
    }

    float wydatki(RadaNadzorcza rada)
    {
        float wydatek;
        cout << "Podaj wysokosc wydatkow: ";
        cin >> wydatek;
        rada.budzet = rada.budzet - wydatek;
        return rada.budzet;
    }

    void aktualny_budzet(RadaNadzorcza rada)
    {
        cout << "Aktualny budzet: " << rada.budzet << endl;
    }

    Data data_planowana(RadaNadzorcza rada)
    {
        time_t t = time(0);
        tm * now = localtime(&t);
        if(rada.data.rok > now->tm_year + 1900)
        {
            cout << "Nie mozna ustawic nowej daty, poniewaz aktualne planowane posiedzenie jeszcze sie nie odbylo." << endl;
        }
        else if (rada.data.rok == now->tm_year + 1900 && rada.data.miesiac > now->tm_mon + 1)
        {
            cout << "Nie mozna ustawic nowej daty, poniewaz aktualne planowane posiedzenie jeszcze sie nie odbylo." << endl;
        }
        else if(rada.data.rok == now->tm_year + 1900 && rada.data.miesiac == now->tm_mon + 1 && rada.data.dzien > now->tm_mday)
        {
            cout << "Nie mozna ustawic nowej daty, poniewaz aktualne planowane posiedzenie jeszcze sie nie odbylo." << endl;
        }
        else
        {
            cout << "Podaj rok planowanego zgromadzenia rady: ";
            cin >> rada.data.rok;
            cout << "Podaj miesiac planowanego zgromadzenia rady: ";
            cin >> rada.data.miesiac;
            cout << "Podaj dzien planowanego posiedzenia rady: ";
            cin >> rada.data.dzien;
            while ((rada.data.rok < now->tm_year + 1900) || (rada.data.rok == now->tm_year + 1900  && rada.data.miesiac < now->tm_mon + 1) || (rada.data.rok == now->tm_year + 1900 && rada.data.miesiac == now->tm_mon + 1 && rada.data.dzien < now->tm_mday))
            {
                cout << "Podales niepoprawna date!" << endl;
                cout << "Podaj rok planowanego zgromadzenia rady: ";
                cin >> rada.data.rok;
                cout << "Podaj miesiac planowanego zgromadzenia rady: ";
                cin >> rada.data.miesiac;
                cout << "Podaj dzien planowanego posiedzenia rady: ";
                cin >> rada.data.dzien;
            }
        }
        return rada.data;
        

    }

    void ostatnia_data(RadaNadzorcza rada)
    {
        cout << "Data ostatniego zgromadzenia: " << rada.data.dzien << "." << rada.data.miesiac << "." << rada.data.rok << endl;
    }

    int liczba_kobiet1(RadaNadzorcza rada)
    {
        int lk;
        cout << "Podaj aktualna liczbe kobiet w zarzadzie: ";
        cin >> lk;
        return lk;
    }

    void liczba_kobiet2(RadaNadzorcza rada)
    {
        cout << "Aktualna liczba kobiet w zarzadzie: " << rada.liczba_kobiet << endl;
    }

    void liczba_mezczyzn(RadaNadzorcza rada)
    {
        cout << "Aktualna liczba mezczyzn w zarzadzie: " << rada.liczba_czlonkow - rada.liczba_kobiet << endl;
    }

};

int main()
{
    RadaNadzorcza rada;
    rada.liczba_czlonkow = 0;
    rada.srednia_uchwal = 0;
    rada.budzet = 0;
    rada.data.dzien = 0;
    rada.data.rok = 0;
    rada.data.miesiac = 0;
    rada.liczba_kobiet = 0;
    int x;
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
                rada.liczba_czlonkow = rada.liczba_powolanych(rada);
                break;
            case 2:
                rada.liczba_czlonkow = rada.liczba_odwolanych(rada);
                break;
            case 3:
                rada.aktualna_liczba(rada);
                break;
            case 4:
                rada.srednia_uchwal = rada.uchwaly_poprzedni_rok(rada);
                break;
            case 5:
                rada.aktualna_srednia(rada);
                break;
            case 6:
                rada.budzet = rada.wplywy(rada);
                break;
            case 7:
                rada.budzet = rada.wydatki(rada);
                break;
            case 8:
                rada.aktualny_budzet(rada);
                break;
            case 9:
                rada.data = rada.data_planowana(rada);
                break;
            case 10:
                rada.ostatnia_data(rada);
                break;
            case 11:
                rada.liczba_kobiet = rada.liczba_kobiet1(rada);
                break;
            case 12:
                rada.liczba_kobiet2(rada);
                break;
            case 13:
                rada.liczba_mezczyzn(rada);
                break;
            case 14:
                break;
            default:
                cout << "Niepoprawna liczba" << endl;
                break;

        }
    }
    return 0;
}

