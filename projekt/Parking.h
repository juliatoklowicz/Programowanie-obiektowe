#ifndef PARKING_H
#define PARKING_H

#include <string>
#include <vector>
#include "HotelManagement.h"
using namespace std;

class Parking
{
private:
    int parking_space_id;
    string type_of_parking_space;
    int rent_for_parking_space;
    bool booked;
protected:
    string customer_first_name;
    string customer_last_name;
public:
    Parking();
    Parking(int id, string type, int rent, vector <Parking> v);
    void addParkingSpace(vector <Parking> v);
    vector <Parking> removeParkingSpace(vector <Parking> v);
    void getInformation();

    friend class HotelManagement;

};

#endif