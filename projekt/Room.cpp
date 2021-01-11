#include "Room.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

Room::Room()
{
    room_id = 0;
    rent_per_night = 0;
    type = "";
    customer_first_name = "";
    customer_last_name = "";
    booked = false;
}

Room::Room(int id, int rent, string typ, vector <Room> v)
{
    room_id = id;
    rent_per_night = rent;
    type = typ;
    booked = false;
    bool debug = false;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].room_id == id)
            debug = true;
    }

    while(debug == true)
    {
        cout << "Room already exists! Try again." << endl;
        cout << "Enter room ID: ";
        cin >> id;
        room_id = id;
        debug = false;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].room_id == id)
                debug = true;
        }
    }
}

void Room::addRoom(vector <Room> v)
{
    int id;
    cout << "Enter room ID: ";
    cin >> id;
    room_id = id;
    cout << "Enter rent per night for room: ";
    cin >> rent_per_night;
    cout <<  "Enter type of room (regular/apartment)";
    cin >> type;
    bool debug = false;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].room_id == id)
            debug = true;
    }

    while(debug == true)
    {
        cout << "Room already exists! Try again." << endl;
        cout << "Enter room ID: ";
        cin >> id;
        room_id = id;
        debug = false;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].room_id == id)
                debug = true;
        }
    }

    cout << "Room added" << endl;
}

vector <Room> Room::removeRoom (vector <Room> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].room_id == room_id)
        {
            v.erase(v.begin()+i);
        }
    }
    cout << "Room removed" << endl; 
    return v;
}

void Room::getInformation()
{
    cout << "Room ID: " << room_id << endl;
    cout << "Type: " << type << endl;
    cout << "Rent per night: " << rent_per_night << endl;
    cout << "Booked: ";
    if (booked == true)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    
}