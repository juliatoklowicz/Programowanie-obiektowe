#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"
#include "HotelManagement.h"
#include <vector>

using namespace std;

class Employee : public Person
{
private:
    int salary;
public:
    Employee();
    Employee(string a, string b, int c, vector <Employee> v);
    void addEmployee(vector <Employee> v);
    vector <Employee> fireEmployee(vector <Employee> v);
    void setSalary();
    int getSalary();
    void setFirstName();
    void setLastName();
    string getFirstName();
    string getLastName();
    void getInformation();

    friend class HotelManagement;
};

#endif