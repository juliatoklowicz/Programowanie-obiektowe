#include "Person.h"
#include "Employee.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Employee::Employee()
{
    first_name = "";
    last_name = "";
    salary = 0;
}

Employee::Employee(string a, string b, int c, vector <Employee> v)
{
    first_name = a;
    last_name = b;
    salary = c;
    bool debug = false;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].first_name == a && v[i].last_name == b)
        {
            debug = true;
        }
    }
    while(debug == true)
    {
        cout << "Employee already exists! Try again." << endl;
        cout << "Enter first name: ";
        cin >> a;
        first_name = a;
        cout << "Enter last name: ";
        cin >> b;
        last_name = b;
        debug = false;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].first_name == a && v[i].last_name == b)
            {
                debug = true;
            }
        }
    }
}

void Employee::setSalary()
{
    cout << "Enter salary: ";
    cin >> salary;
}

int Employee::getSalary()
{
    return salary;
}

void Employee::setFirstName()
{
    cout << "Enter first name: ";
    cin >> first_name;
}

void Employee::setLastName()
{
    cout << "Enter last name: ";
    cin >> last_name;
}

string Employee::getFirstName()
{
    return first_name;
}

string Employee::getLastName()
{
    return last_name;
}

void Employee::addEmployee(vector <Employee> v)
{
    string a,b;
    cout << "Enter first name: ";
    cin >> a;
    first_name = a;
    cout << "Enter last name: ";
    cin >> b;
    last_name = b;
    cout << "Enter salary: ";
    cin >> salary;
    bool debug = false;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].first_name == a && v[i].last_name == b)
        {
            debug = true;
        }
    }
    while(debug == true)
    {
        cout << "Employee already exists! Try again." << endl;
        cout << "Enter first name: ";
        cin >> first_name;
        cout << "Enter last name: ";
        cin >> last_name;
        debug = false;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].first_name == a && v[i].last_name == b)
            {
                debug = true;
            }
        }
    }
    cout << "Employee added" << endl;

}

void Employee::getInformation()
{
    cout << "First name: " << first_name << endl;
    cout << "Last name: " << last_name << endl;
    cout << "Salary: " << salary << endl;
}

vector <Employee> Employee::fireEmployee(vector <Employee> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].first_name == first_name && v[i].last_name == last_name)
        {
            v.erase(v.begin()+i);
        }
    }
    cout << "Employee fired" << endl; 
    return v;

}