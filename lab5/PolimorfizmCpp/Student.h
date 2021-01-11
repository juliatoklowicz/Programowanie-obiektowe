#ifndef STUDENT_H
#define STUDENT_H

#include <vector>
#include <string>
#include "Osoba.h"

using namespace std;

class Student : public Osoba
{
private:
    vector <int> polski;
    vector <int> matematyka;
    vector <int> angielski;
public:
    Student();
    Student(Student &student);
    Student(Student &&student);
    Student(int x);
    ~Student();
    void dodaj_ocene();
    void odczytaj_ocene();
    void lista_ocen();
    void przedstaw();
};
#endif