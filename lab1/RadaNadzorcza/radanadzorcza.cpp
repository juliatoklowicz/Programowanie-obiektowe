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
private:
    int liczba_czlonkow;
    int srednia_uchwal;
    float budzet;
    Data data;
    int liczba_kobiet;
public:
    void wyzeruj()
    {
        liczba_czlonkow = 0;
        srednia_uchwal = 0;
        budzet = 0;
        data.dzien = 0;
        data.rok = 0;
        data.miesiac = 0;
        liczba_kobiet = 0;
    }
    void liczba_powolanych()
    {
        int l1;
        cout << "Podaj liczbe czlonkow powolanych przez walne zgromadzenie: ";
        cin >> l1;
        liczba_czlonkow = liczba_czlonkow + l1;
    }

    void liczba_odwolanych()
    {
        int l2;
        cout << "Podaj liczbe czlonkow odwolanych przez walne zgromadzenie: ";
        cin >> l2;
        while (l2 > liczba_czlonkow)
        {
            cout << "Liczba czlonkow nie moze spasc ponizej 0!" << endl;
            cout << "Podaj prawidlowa liczbe czlonkow odwolanych przez walne zgromadzenie: ";
            cin >> l2;
        }
        liczba_czlonkow = liczba_czlonkow - l2;
    }

    void aktualna_liczba()
    {
        cout << "Aktualna liczba czlonkow rady nadzorczej wynosi: " << liczba_czlonkow << endl;
    }

    void uchwaly_poprzedni_rok()
    {
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
        srednia_uchwal = y;
    }

    void aktualna_srednia()
    {
        cout << "Aktualna srednia liczba wydanych uchwal: " << srednia_uchwal << endl;
    }

    void wplywy()
    {
        float wplyw;
        cout << "Podaj wartosc wplywu do budzetu: ";
        cin >> wplyw;
        budzet = budzet + wplyw;
    }

    void wydatki()
    {
        float wydatek;
        cout << "Podaj wysokosc wydatkow: ";
        cin >> wydatek;
        budzet = budzet - wydatek;
    }

    void aktualny_budzet()
    {
        cout << "Aktualny budzet: " << budzet << endl;
    }

    void data_planowana()
    {
        time_t t = time(0);
        tm * now = localtime(&t);
        if(data.rok > now->tm_year + 1900)
        {
            cout << "Nie mozna ustawic nowej daty, poniewaz aktualne planowane posiedzenie jeszcze sie nie odbylo." << endl;
        }
        else if (data.rok == now->tm_year + 1900 && data.miesiac > now->tm_mon + 1)
        {
            cout << "Nie mozna ustawic nowej daty, poniewaz aktualne planowane posiedzenie jeszcze sie nie odbylo." << endl;
        }
        else if(data.rok == now->tm_year + 1900 && data.miesiac == now->tm_mon + 1 && data.dzien > now->tm_mday)
        {
            cout << "Nie mozna ustawic nowej daty, poniewaz aktualne planowane posiedzenie jeszcze sie nie odbylo." << endl;
        }
        else
        {
            cout << "Podaj rok planowanego zgromadzenia rady: ";
            cin >> data.rok;
            cout << "Podaj miesiac planowanego zgromadzenia rady: ";
            cin >> data.miesiac;
            cout << "Podaj dzien planowanego posiedzenia rady: ";
            cin >> data.dzien;
            while ((data.rok < now->tm_year + 1900) || (data.rok == now->tm_year + 1900  && data.miesiac < now->tm_mon + 1) || (data.rok == now->tm_year + 1900 && data.miesiac == now->tm_mon + 1 && data.dzien < now->tm_mday))
            {
                cout << "Podales niepoprawna date!" << endl;
                cout << "Podaj rok planowanego zgromadzenia rady: ";
                cin >> data.rok;
                cout << "Podaj miesiac planowanego zgromadzenia rady: ";
                cin >> data.miesiac;
                cout << "Podaj dzien planowanego posiedzenia rady: ";
                cin >> data.dzien;
            }
        }        

    }

    void ostatnia_data()
    {
        cout << "Data ostatniego zgromadzenia: " << data.dzien << "." << data.miesiac << "." << data.rok << endl;
    }

    void liczba_kobiet1()
    {
        int lk;
        cout << "Podaj aktualna liczbe kobiet w zarzadzie: ";
        cin >> lk;
        liczba_kobiet = lk;
    }

    void liczba_kobiet2()
    {
        cout << "Aktualna liczba kobiet w zarzadzie: " << liczba_kobiet << endl;
    }

    void liczba_mezczyzn()
    {
        cout << "Aktualna liczba mezczyzn w zarzadzie: " << liczba_czlonkow - liczba_kobiet << endl;
    }

};

int main()
{
    RadaNadzorcza rada;
    rada.wyzeruj();
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
    return 0;
}

