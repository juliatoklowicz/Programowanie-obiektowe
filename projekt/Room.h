#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>

#include "HotelManagement.h"

using namespace std;

class Room
{
public:
    int room_id;
    int rent_per_night;
    string type;
    string customer_first_name;
    string customer_last_name;
    bool booked;

    Room();
    Room(int id, int rent, string typ, vector <Room> v);
    void addRoom(vector <Room> v);
    vector <Room> removeRoom (vector <Room> v);
    void getInformation();

    friend class HotelManagement;
};

#endif