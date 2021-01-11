#ifndef HOTELMANAGEMENT_H
#define HOTELMANAGEMENT_H

#include "Customer.h"
#include "Parking.h"
#include "Room.h"
#include "Employee.h"
#include <vector>
#include <string>
#include <tuple>

using namespace std;


class Customer;
class Parking;
class Room;
class Employee;

struct Result
{
    vector <Customer> customers;
    vector <Room> rooms;
    vector <Parking> parkings;
};

class HotelManagement
{
public:
    void sortCustomers(vector <Customer> customers);
    void findCustomer(vector <Customer> customers);
    void sortParkingSpaces(vector <Parking> parkings);
    void findParkingSpace(vector <Parking> parkings);
    void sortRooms(vector <Room> rooms);
    void findRoom(vector <Room> rooms);
    void guestRaport(vector <Customer> customers);
    Result bookRoom(vector <Customer> customers, vector <Room> rooms, vector <Parking> parkings);
    void getAvailRooms(vector <Room> rooms);
    int generateBill(vector <Customer> customers, vector <Room> rooms, vector <Parking> parkings);
    void findCurrentCustomers(vector <Customer> customers);
    void dayFinanceReport(vector <Customer> customers, vector <Room> rooms, vector <Parking> parkings);
    void monthFinanceReport(vector <Customer> customers, vector <Room> rooms, vector <Parking> parkings);
    void yearFinanceReport(vector <Customer> customers, vector <Room> rooms, vector <Parking> parkings);
    void employeeReport(vector <Employee> employees);
};

#endif