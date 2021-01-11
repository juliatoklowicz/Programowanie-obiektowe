#include <iostream>
#include <string>
#include <vector>
#include "Student.h"
#include "Osoba.h"

using namespace std;

Student::Student() : Osoba() //konstruktor domyslny
{
    
}

Student::Student(Student &student) : Osoba(student) //konstruktor kopiujacy
{
    
}

Student::Student(Student &&student) : Osoba(student) //konstruktor przenoszacy
{
    
}

Student::Student(int x) //konstruktor konwertujacy
{
    polski.push_back(x);
}

void Student::dodaj_ocene()
{
    int x,y;
    cout << "Wybierz przedmiot, z ktorego chcesz dodac ocene. Wpisz liczbe 1-3, gdzie 1-j.polski, 2-matematyka, 3-j.angielski: ";
    cin >> x;
    cout << "Wpisz, jaka ocene chcesz dodac (1-5): ";
    cin >> y;
    switch(x)
    {
        case 1:
            polski.push_back(y);
            break;
        case 2:
            matematyka.push_back(y);
            break;
        case 3:
            angielski.push_back(y);
            break;
        default:
            cout << "Niepoprawna liczba" << endl;
            break;
    }
    cout << endl;
}

void Student::odczytaj_ocene()
{
    int x;
    cout << "Wybierz przedmiot, z ktorego chcesz odczytac oceny. Wpisz liczbe 1-3, gdzie 1-j.polski, 2-matematyka, 3-j.angielski: ";
    cin >> x;
    switch(x)
    {
        case 1:
            cout << "Oceny z j.polskiego: " << endl;
            for (int i = 0; i < polski.size(); i++)
            {
                cout << polski[i] << " ";
            }
            break;
        case 2:
            cout << "Oceny z matematyki: " << endl;
            for (int i = 0; i < matematyka.size(); i++)
            {
                cout << matematyka[i] << " ";
            }
            break;
        case 3:
            cout << "Oceny z j.angielskiego: " << endl;
            for (int i = 0; i < angielski.size(); i++)
            {
                cout << angielski[i] << " ";
            }
            break;
        default:
            cout << "Niepoprawna liczba" << endl;
            break;
    }
    cout << endl;

}

void Student::lista_ocen()
{
    cout << "Oceny z j.polskiego: " << endl;
    for (int i = 0; i < polski.size(); i++)
    {
        cout << polski[i] << " ";
    }
    cout << endl;
    cout << "Oceny z matematyki: " << endl;
    for (int i = 0; i < matematyka.size(); i++)
    {
        cout << matematyka[i] << " ";
    }
    cout << endl;
    cout << "Oceny z j.angielskiego: " << endl;
    for (int i = 0; i < angielski.size(); i++)
    {
        cout << angielski[i] << " ";
    }
    cout << endl;
}

void Student::przedstaw()
{
    Osoba::przedstaw();
    cout << "Oceny z j.polskiego: " << endl;
    for (int i = 0; i < polski.size(); i++)
    {
        cout << polski[i] << " ";
    }
    cout << endl;
    cout << "Oceny z matematyki: " << endl;
    for (int i = 0; i < matematyka.size(); i++)
    {
        cout << matematyka[i] << " ";
    }
    cout << endl;
    cout << "Oceny z j.angielskiego: " << endl;
    for (int i = 0; i < angielski.size(); i++)
    {
        cout << angielski[i] << " ";
    }

}

Student::~Student()
{

}