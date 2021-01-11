#include "Person.h"
#include "Customer.h"
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

Customer::Customer()
{
    first_name = "";
    last_name = "";
    phone = "0";
    room_id = 0;
    from_date.day = 0;
    from_date.month = 0;
    from_date.year = 0;
    to_date.day = 0;
    to_date.month = 0;
    to_date.year = 0;
    breakfast = false;
    dinner = false;
    parking = false;
    parking_id = 0;
}

Customer::Customer(string name1, string name2, string phone_number, vector <Customer> v)
{
    first_name = name1;
    last_name = name2;
    phone = phone_number;
    room_id = 0;
    from_date.day = 0;
    from_date.month = 0;
    from_date.year = 0;
    to_date.day = 0;
    to_date.month = 0;
    to_date.year = 0;
    breakfast = false;
    dinner = false;
    parking = false;
    parking_id = 0;
    bool debug = false;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].first_name == name1 && v[i].last_name == name2)
        {
            debug = true;
        }
    }

    while(debug == true)
    {
        cout << "Customer already exists! Try again." << endl;
        cout << "Enter first name: ";
        cin >> name1;
        first_name = name1;
        cout << "Enter last name: ";
        cin >> name2;
        last_name = name2;
        debug = false;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].first_name == name1 && v[i].last_name == name2)
            {
                debug = true;
            }
        }
    }
    /*time_t t = time(0);
    tm * now = localtime(&t);
    while ((year1 < now->tm_year + 1900) || (year1 == now->tm_year + 1900  && mon1 < now->tm_mon + 1) || (year1== now->tm_year + 1900 && mon1 == now->tm_mon + 1 && day1 < now->tm_mday))
    {
        cout << "You entered an incorrect arrival date! Try again." << endl;
        cout << "Enter arrival date. Day: ";
        cin >> day1;
        cout << "Month: ";
        cin >> mon1;
        cout << "Year: ";
        cin >> year1;
        from_date.day = day1;
        from_date.month = mon1;
        from_date.year = year1;
    }
    while ((year2 < now->tm_year + 1900) || (year2 == now->tm_year + 1900  && mon2 < now->tm_mon + 1) || (year2== now->tm_year + 1900 && mon2 == now->tm_mon + 1 && day2 < now->tm_mday))
    {
        while((year2 < year1) || (year2 == year1 && mon2 < mon1) || (year2 == year1 && mon2 == mon1 && day2 < day1))
        {
            cout << "You entered an incorrect departure date! Try again." << endl;
            cout << "Enter departure date. Day: ";
            cin >> day2;
            cout << "Month: ";
            cin >> mon2;
            cout << "Year: ";
            cin >> year2;
            to_date.day = day2;
            to_date.month = mon2;
            to_date.year = year2;
        }
        
    }
    */

}

void Customer::addCustomer(vector <Customer> v)
{
    int day1,mon1,year1,day2,mon2,year2;
    string answer, name1, name2;
    cout << "Enter first name: ";
    cin >> name1;
    first_name = name1;
    cout << "Enter last name: ";
    cin >> name2;
    last_name = name2;
    cout << "Enter phone number: ";
    cin >> phone;
    cout << "Enter room ID: ";
    cin >> room_id;
    cout << "Enter arrival date. Day: ";
    cin >> day1;
    from_date.day = day1;
    cout << "Month: ";
    cin >> mon1;
    from_date.month = mon1;
    cout << "Year: ";
    cin >> year1;
    from_date.year = year1;
    cout << "Enter departure date. Day: ";
    cin >> day2;
    to_date.day = day2;
    cout << "Month: ";
    cin >> mon2;
    to_date.month = mon2;
    cout << "Year: ";
    cin >> year2;
    to_date.year = year2;
    cout << "Do you want breakfast? y/n: ";
    cin >> answer;
    if (answer == "y")
        breakfast = true;
    else
        breakfast = false;
    cout << "Do you want dinner? y/n: ";
    cin >> answer;
    if (answer == "y")
        dinner = true;
    else
        dinner = false;
    cout << "Do you need parking space? y/n: ";
    cin >> answer;
    if (answer == "y")
        parking = true;
    else
        parking = false;

    bool debug = false;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].first_name == name1 && v[i].last_name == name2)
        {
            debug = true;
        }
    }
    while(debug == true)
    {
        cout << "Customer already exists! Try again." << endl;
        cout << "Enter first name: ";
        cin >> name1;
        first_name = name1;
        cout << "Enter last name: ";
        cin >> name2;
        last_name = name2;
        debug = false;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].first_name == name1 && v[i].last_name == name2)
            {
                debug = true;
            }
        }
    }
    time_t t = time(0);
    tm * now = localtime(&t);
    while ((year1 < now->tm_year + 1900) || (year1 == now->tm_year + 1900  && mon1 < now->tm_mon + 1) || (year1== now->tm_year + 1900 && mon1 == now->tm_mon + 1 && day1 < now->tm_mday))
    {
        cout << "You entered an incorrect arrival date! Try again." << endl;
        cout << "Enter arrival date. Day: ";
        cin >> day1;
        cout << "Month: ";
        cin >> mon1;
        cout << "Year: ";
        cin >> year1;
        from_date.day = day1;
        from_date.month = mon1;
        from_date.year = year1;
    }
    while ((year2 < now->tm_year + 1900) || (year2 == now->tm_year + 1900  && mon2 < now->tm_mon + 1) || (year2== now->tm_year + 1900 && mon2 == now->tm_mon + 1 && day2 < now->tm_mday))
    {
        while((year2 < year1) || (year2 == year1 && mon2 < mon1) || (year2 == year1 && mon2 == mon1 && day2 < day1))
        {
            cout << "You entered an incorrect departure date! Try again." << endl;
            cout << "Enter departure date. Day: ";
            cin >> day2;
            cout << "Month: ";
            cin >> mon2;
            cout << "Year: ";
            cin >> year2;
            to_date.day = day2;
            to_date.month = mon2;
            to_date.year = year2;
        }
        
    }
    cout << "Customer added" << endl;
}

void Customer::getInformation()
{
    cout << "First name: " << first_name << endl;
    cout << "Last name: " << last_name << endl;
    cout << "Phone number: " << phone << endl;
    cout << "Room ID: " << room_id << endl;
    cout << "Arrival date: " << from_date.day << "." << from_date.month << "." << from_date.year << endl; 
    cout << "Departure date: " << to_date.day << "." << to_date.month << "." << to_date.year << endl;
    cout << "Breakfast: ";
    if (breakfast == true)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    cout << "Dinner: ";
    if (dinner == true)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    cout << "Parking space: ";
    if (parking == true)
    {
        cout << "yes" << endl;
        cout << "Parking space ID: " << parking_id << endl;
    }
    else
        cout << "no" << endl;
}

vector <Customer> Customer::removeCustomer(vector <Customer> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].first_name == first_name && v[i].last_name == last_name)
        {
            v.erase(v.begin()+i);
        }
    }
    cout << "Customer removed" << endl; 
    return v;
}

string Customer::getFirstName()
{
    return first_name;
}

string Customer::getLastName()
{
    return last_name;
}