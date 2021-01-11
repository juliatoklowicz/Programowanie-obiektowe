#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Osoba.h"
#include "Student.h"
#include "Pracownik.h"
#include "FabrykaOsob.h"
#include "FabrykaStudentow.h"
#include "FabrykaPracownikow.h"

using namespace std;

void foo(Osoba &os)
{
    os.przedstaw();
}

void bar(Osoba *os)
{
    os->przedstaw();
}

int main()
{
    //Osoba osoba;
    //osoba.ustaw_nazwisko();
    //osoba.odczytaj_nazwisko();
    //osoba.ustaw_date();
    //osoba.odczytaj_date();
    //osoba.ustaw_adres();
    //osoba.odczytaj_adres();
    //osoba.przedstaw();
    //foo(osoba);
    //bar(&osoba);

    //Student student;
    //student.ustaw_nazwisko();
    //student.odczytaj_nazwisko();
    //student.ustaw_date();
    //student.odczytaj_date();
    //student.ustaw_adres();
    //student.odczytaj_adres();
    //student.dodaj_ocene();
    //student.odczytaj_ocene();
    //student.lista_ocen();
    //student.przedstaw();
    //foo(student);
    //bar(&student);

   // Pracownik pracownik;
    //pracownik.ustaw_nazwisko();
    //pracownik.ustaw_date();
    //pracownik.ustaw_adres();
    //pracownik.dodaj_przedmiot();
    //pracownik.dodaj_przedmiot();
    //pracownik.dodaj_przedmiot();
    //pracownik.usun_przedmiot();
    //pracownik.czy_prowadzi();
    //pracownik.przedstaw();
    //foo(pracownik);
    //bar(&pracownik);

    //Funckje foo i bar wywoluja tylko podstawowa funkcje przedstaw z klasy Osoba dla kazdych z 3 obiektow
    //po zrobieniu funkcji przedstaw jako funkcja wirtualna, funkcje foo i bar wypisuja rowniez reszte informacji w przypadku obiektow klasy Student i Pracownik

    //Pracownik* p1 = new Pracownik;
    //Osoba* o1 = static_cast<Osoba∗>(p1);
    //Osoba* o2 = static_cast<Pracownik∗>(o1); //niepotrzebne
    //Osoba* o3 = new Osoba;
    //Pracownik* p2 = static_cast<Pracownik∗>(o3);
    //wszystkie z powyzszych rzutowan sa poprawne

    //Pracownik∗ p3 = new Pracownik;
    //Osoba* o4 = dynamic_cast<Osoba∗>(p3); //poprawne
    //Pracownik* p4 = dynamic_cast<Osoba∗>(o4); //niepoprawne

    //Osoba* o5 = new Osoba ;
    //Pracownik* p5 = dynamic_cast<Pracownik ∗>(o5 ) ;
    //if(p5 == nullptr)
    //{
    //    cout << "Blad rzutowania!" << endl;
    //}
    //else
    //{
    //    p5 -> lista_przedmiotow();
    //}

    //19. Nie mozna skompilowac projektu, poniewaz nie mozna tworzyc klas abstrakcyjnych z czystymi funkcjami wirtualnymi

    //23. Po dodaniu slowka virtual wszystkie destruktory sa wywolywane przy niszczeniu obiektow

    map<string, FabrykaOsob*> m;
    m["pracownik"] = new FabrykaPracownikow();
    m["student"] = new FabrykaStudentow();
    vector<Osoba*> tablicaOsob;
    string s;
    
    while(true)
    {
        cout << "Podaj co chcesz zrobic (pracownik/student/wyswietl/wyjscie): "; 
        cin >> s;
        if ((s == "pracownik") || (s == "student"))
        {
            tablicaOsob.push_back(m[s]->utworz());
        }      
        else if (s == "wyswietl")
        {
            for (int i = 0; i < tablicaOsob.size(); i++)
            {
                cout << tablicaOsob[i] << endl;
            }
        }
        else if (s == "wyjscie")
        {
            return 0;
        }
    }
    for (auto wsk : tablicaOsob)
    {
        delete wsk;
    }
    
    return 0;
}