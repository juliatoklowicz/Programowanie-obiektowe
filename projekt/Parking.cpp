#include "Parking.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

Parking::Parking()
{
    parking_space_id = 0;
    type_of_parking_space = "";
    rent_for_parking_space = 0;
    customer_first_name = "";
    customer_last_name = "";
    booked = false;
}

Parking::Parking(int id, string type, int rent, vector <Parking> v)
{
    parking_space_id = id;
    type_of_parking_space = type;
    rent_for_parking_space = rent;
    customer_first_name = "";
    customer_last_name = "";
    booked = false;
    bool debug = false;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].parking_space_id == id)
            debug = true;
    }

    while(debug == true)
    {
        cout << "Parking space already exists! Try again." << endl;
        cout << "Enter parking space ID: ";
        cin >> id;
        parking_space_id = id;
        debug = false;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].parking_space_id == id)
                debug = true;
        }
    }
}

void Parking::addParkingSpace(vector <Parking> v)
{
    int id;
    cout << "Enter parking space ID: ";
    cin >> id;
    parking_space_id = id;
    cout << "Enter type of parking space (regular/for_disabled): ";
    cin >> type_of_parking_space;
    cout << "Enter rent per night for parking space: ";
    cin >> rent_for_parking_space;
    bool debug = false;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].parking_space_id == id)
            debug = true;
    }

    while(debug == true)
    {
        cout << "Parking space already exists! Try again." << endl;
        cout << "Enter parking space ID: ";
        cin >> id;
        parking_space_id = id;
        debug = false;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].parking_space_id == id)
                debug = true;
        }
    }
    cout << "Parking space added" << endl;
}

vector <Parking> Parking::removeParkingSpace(vector <Parking> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].parking_space_id == parking_space_id)
        {
            v.erase(v.begin()+i);
        }
    }
    cout << "Parking space removed" << endl; 
    return v;
}

void Parking::getInformation()
{
    cout << "Parking space ID: " << parking_space_id << endl;
    cout << "Type: " << type_of_parking_space << endl;
    cout << "Rent per night: " << rent_for_parking_space << endl;
    cout << "Booked: ";
    if (booked == false)
        cout << "no" << endl;
    else
        cout << "yes" << endl;
    
}