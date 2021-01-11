#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

struct cmp
    {
        bool operator () ( Samochod &a, Samochod &b) const
        {
            return a.odczytaj_pojemnosc_baku() < b.odczytaj_pojemnosc_baku();
        }
    };

class Samochod
{
 private:
    float pojemnosc_baku;
    float poziom_paliwa;
    unsigned int liczba_kilometrow;
    string model;

public:
    Samochod();
    Samochod(string m, float p);
    float odczytaj_pojemnosc_baku();
    void wyswietl_paliwo();
    void wyswietl_km();
    void wyswietl_model();
    void zmien_przebieg();

    operator bool () const 
    {
        if (pojemnosc_baku > 0 && model != "")
        {
            return true;
        }
        else
        {
            cout << "false" << endl;
            return false;
        }
        
    }

    bool operator ! () const
    {
        if (pojemnosc_baku > 0 && model != "")
            return false;
        else
            return true;
    }


    friend ostream & operator << (ostream &os, const Samochod &samochod)
    {
        os << samochod.model << " " << samochod.poziom_paliwa << endl;
        return os;
    }

    //powyzszy kod uzywa friend, poniewaz "mianuje" klase ostream przyjacielem klasy Samochod, aby miala
    //dostep do pol klasy, ktore sa ustawione jako private

    bool operator < (const Samochod &samochod) const
    {
        return this->model < samochod.model;
    }

    int operator ++ (int i) const
    {
        i+=2;
        return i;
    }

    bool operator , (Samochod samochod) const
    {
        if (samochod)
            return true;
        else
        {
            return false;
        }
        
    }

    bool operator |= (Samochod s1) const
    {
        if (s1.pojemnosc_baku = s1.poziom_paliwa)
            return true;
        else
        {
            return false;
        }
        
    }
};

Samochod::Samochod()
{
    pojemnosc_baku = 30;
    poziom_paliwa = 0,75;
    liczba_kilometrow = 1200;
    model = ""; 

}

Samochod::Samochod(string m, float p)
{
    model = m;
    pojemnosc_baku = p;
}


float Samochod::odczytaj_pojemnosc_baku()
{
    return pojemnosc_baku;
}

void Samochod::wyswietl_paliwo()
{
    cout << "Aktualny poziom paliwa: " << poziom_paliwa << endl;
}

void Samochod::wyswietl_km()
{
    cout << "Aktualny przebieg samochodu: " << liczba_kilometrow << endl;
}

void Samochod::wyswietl_model()
{
    cout << "Model samochodu: " << model << endl;
}

void Samochod::zmien_przebieg()
{
    unsigned int przebieg;
    cout << "Podaj o ile chcesz zwiekszyc przebieg samochodu: " << endl;
    cin >> przebieg;
    liczba_kilometrow += przebieg;
}

int main()
{
    Samochod s1 ("audi" , 123 );
    Samochod s2 ("bmw" , 0);
    Samochod s3 ("" , 200);
    if (s1)
    {
        cout << "s1 true" << endl;
    }
    if (!s1)
    {
        cout << "s1 false" << endl;
    } 

    vector <Samochod> v;
    v.push_back(s1);
    v.push_back(s2);
    v.push_back(s3);
    sort(v.begin(), v.end());
    for( auto it= v.begin(); it != v.end(); ++it)
    {
        cout << *it << endl;
    }

    //set <Samochod, cmp> s;
    //s.insert(s1);
    //s.insert(s2);
    //s.insert(s3);
    //for (auto it=s.begin(); it!=s.end(); ++it)
    //{
    //    cout << *it << endl;
    //}

    return 0;
}