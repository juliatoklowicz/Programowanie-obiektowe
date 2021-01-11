#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Person.h"
#include "HotelManagement.h"
#include <vector>

using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};

class Customer : public Person
{
private:
    string phone;
protected:
    int room_id;
    Date from_date;
    Date to_date;
    bool breakfast;
    bool dinner;
    bool parking;
    int parking_id;
public:
    Customer();
    Customer(string name1, string name2, string phone_number, vector <Customer> v);
    void addCustomer(vector <Customer> v);
    vector <Customer> removeCustomer(vector <Customer> v);
    void getInformation();
    string getFirstName();
    string getLastName();

    friend class HotelManagement;
};

#endif