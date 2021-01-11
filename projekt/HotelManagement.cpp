#include "HotelManagement.h"
#include "Customer.h"
#include "Employee.h"
#include "Parking.h"
#include "Room.h"

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <tuple>

using namespace std;


void swap_customers(Customer *xp, Customer *yp)  
{  
    Customer temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
} 

void swap_parkings(Parking *xp, Parking *yp)  
{  
    Parking temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
} 

void swap_rooms(Room *xp, Room *yp)  
{  
    Room temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
} 

void HotelManagement::sortCustomers(vector <Customer> customers)
{
    int x, i, j;
    int n = customers.size();
    cout << "1. Sort by name." << endl;
    cout << "2. Sort by room ID." << endl;
    cout << "3. Sort by arrival date." << endl;
    cout << "4. Sort by departure date." << endl;
    cout << "Enter number from 1 to 4: ";
    cin >> x;

    switch(x)
    {
        case 1: 
            for (i = 0; i < n-1; i++)       
                for (j = 0; j < n-i-1; j++)  
                    if (customers[j].last_name > customers[j+1].last_name)  
                        swap_customers(&customers[j], &customers[j+1]); 
            for(i = 0; i < customers.size(); i++)
            {
                customers[i].getInformation();
            }
            break;
        case 2:
            for (i = 0; i < n-1; i++)       
                for (j = 0; j < n-i-1; j++)  
                    if (customers[j].room_id > customers[j+1].room_id)  
                        swap_customers(&customers[j], &customers[j+1]); 
            for(i = 0; i < customers.size(); i++)
            {
                customers[i].getInformation();
            }
            break;
        case 3: 
            for (i = 0; i < n-1; i++)       
                for (j = 0; j < n-i-1; j++)  
                    if ((customers[j].from_date.year > customers[j+1].from_date.year) || (customers[j].from_date.year == customers[j+1].from_date.year && customers[j].from_date.month > customers[j+1].from_date.month) || (customers[j].from_date.year == customers[j+1].from_date.year && customers[j].from_date.month == customers[j+1].from_date.month && customers[j].from_date.day > customers[j+1].from_date.day))  
                        swap_customers(&customers[j], &customers[j+1]); 
            for(i = 0; i < customers.size(); i++)
            {
                customers[i].getInformation();
            }
            break;  
        case 4: 
            for (i = 0; i < n-1; i++)       
                for (j = 0; j < n-i-1; j++)  
                    if ((customers[j].to_date.year > customers[j+1].to_date.year) || (customers[j].to_date.year == customers[j+1].to_date.year && customers[j].to_date.month > customers[j+1].to_date.month) || (customers[j].to_date.year == customers[j+1].to_date.year && customers[j].to_date.month == customers[j+1].to_date.month && customers[j].to_date.day > customers[j+1].to_date.day))  
                        swap_customers(&customers[j], &customers[j+1]); 
            for(i = 0; i < customers.size(); i++)
            {
                customers[i].getInformation();
            }
            break;
        default:
            cout << "Invalid number" << endl;
    }
}

void HotelManagement::findCustomer(vector <Customer> customers)
{
    string a,b;
    bool debug = false;
    cout << "Enter first name of the customer that you want to find: ";
    cin >> a;
    cout << "Enter last name of the customer that you want to find: ";
    cin >> b;
    for (int i = 0; i < customers.size(); i++)
    {
        if (customers[i].first_name == a && customers[i].last_name == b)
        {
            customers[i].getInformation();
            debug = true;
        }
    }

    if(debug == false)
    {
        cout << "There is no such customer" << endl;
    }


}

void HotelManagement::sortParkingSpaces(vector <Parking> parkings)
{
    int i,j;
    int x;
    int n = parkings.size();
    cout << "1. Sort by parking space ID." << endl;
    cout << "2. Sort by parking space type." << endl;
    cout << "3. Sort by parking space rent per night." << endl;
    cout << "Enter number from 1 to 3: ";
    cin >> x;

    switch(x)
    {
        case 1:
            for (i = 0; i < n-1; i++)       
                for (j = 0; j < n-i-1; j++)  
                    if (parkings[j].parking_space_id > parkings[j+1].parking_space_id)  
                        swap_parkings(&parkings[j], &parkings[j+1]); 
            for(i = 0; i < parkings.size(); i++)
            {
                parkings[i].getInformation();
            }
            break;
        case 2: 
            for (i = 0; i < n-1; i++)       
                for (j = 0; j < n-i-1; j++)  
                    if (parkings[j].type_of_parking_space > parkings[j+1].type_of_parking_space)  
                        swap_parkings(&parkings[j], &parkings[j+1]); 
            for(i = 0; i < parkings.size(); i++)
            {
                parkings[i].getInformation();
            }
            break;
        case 3:
            for (i = 0; i < n-1; i++)       
                for (j = 0; j < n-i-1; j++)  
                    if (parkings[j].rent_for_parking_space > parkings[j+1].rent_for_parking_space)
                        swap_parkings(&parkings[j], &parkings[j+1]); 
            for(i = 0; i < parkings.size(); i++)
            {
                parkings[i].getInformation();
            }
            break;  
        default:
            cout << "Invalid number" << endl;
    }
}

void HotelManagement::findParkingSpace(vector <Parking> parkings)
{
    int id;
    bool debug = false;
    cout << "Enter ID of the parking space that you want to find: ";
    cin >> id;
    for (int i = 0; i < parkings.size(); i++)
    {
        if (parkings[i].parking_space_id == id)
        {
            parkings[i].getInformation();
            debug = true;
        }
    }

    if(debug == false)
    {
        cout << "There is no such parking space" << endl;
    }

}

void HotelManagement::sortRooms(vector <Room> rooms)
{
    int i,j;
    int x;
    int n = rooms.size();
    cout << "1. Sort by room ID." << endl;
    cout << "2. Sort by rent per night for the room." << endl;
    cout << "3. Sort by type of the room." << endl;
    cout << "Enter number from 1 to 3: ";
    cin >> x;
    switch(x)
    {
        case 1:  
            for (i = 0; i < n-1; i++)       
                for (j = 0; j < n-i-1; j++)  
                    if (rooms[j].room_id > rooms[j+1].room_id)  
                        swap_rooms(&rooms[j], &rooms[j+1]); 
            for(i = 0; i < rooms.size(); i++)
            {
                rooms[i].getInformation();
            }
            break;
        case 2:  
            for (i = 0; i < n-1; i++)       
                for (j = 0; j < n-i-1; j++)  
                    if (rooms[j].rent_per_night > rooms[j+1].rent_per_night)  
                        swap_rooms(&rooms[j], &rooms[j+1]); 
            for(i = 0; i < rooms.size(); i++)
            {
                rooms[i].getInformation();
            }
            break;
        case 3: 
            for (i = 0; i < n-1; i++)       
                for (j = 0; j < n-i-1; j++)  
                    if (rooms[j].type > rooms[j+1].type)
                        swap_rooms(&rooms[j], &rooms[j+1]); 
            for(i = 0; i < rooms.size(); i++)
            {
                rooms[i].getInformation();
            }
            break;  
        default:
            cout << "Invalid number" << endl;
    }
}

void HotelManagement::findRoom(vector <Room> rooms)
{
    time_t t = time(0);
    tm * now = localtime(&t);
    int id;
    bool debug = false;
    cout << "Enter ID of the room that you want to find: ";
    cin >> id;
    for (int i = 0; i < rooms.size(); i++)
    {
        if (rooms[i].room_id == id)
        {
            rooms[i].getInformation();
            debug = true;
        }
    }

    if(debug == false)
    {
        cout << "There is no such room" << endl;
    }
}

void HotelManagement::guestRaport(vector <Customer> customers)
{
    for (int i = 0; i < customers.size(); i++)
    {
        customers[i].getInformation();
    }
}

Result HotelManagement::bookRoom(vector <Customer> customers, vector <Room> rooms, vector <Parking> parkings)
{
    Result s;
    int day1,day2,mon1,mon2,year1,year2,id,x,y, park;
    string a,b, answer;
    bool debug = false;
    bool rom = false;
    cout << "Enter first name of the customer you want to book a room for: ";
    cin >> a;
    cout << "Enter last name of the customer you want to book a room for: ";
    cin >> b;
    for (int i = 0; i < customers.size(); i++)
    {
        if (customers[i].first_name == a && customers[i].last_name == b)
        {
            cout << "Enter arrival date. Day: ";
            cin >> day1;
            customers[i].from_date.day = day1;
            cout << "Month: ";
            cin >> mon1;
            customers[i].from_date.month = mon1;
            cout << "Year: ";
            cin >> year1;
            customers[i].from_date.year = year1;
            cout << "Enter departure date. Day: ";
            cin >> day2;
            customers[i].to_date.day = day2;
            cout << "Month: ";
            cin >> mon2;
            customers[i].to_date.month = mon2;
            cout << "Year: ";
            cin >> year2;
            customers[i].to_date.year = year2;
            cout << "Do you want breakfast? y/n: ";
            cin >> answer;
            if (answer == "y")
                customers[i].breakfast = true;
            else
                customers[i].breakfast = false;
            cout << "Do you want dinner? y/n: ";
            cin >> answer;
            if (answer == "y")
                customers[i].dinner = true;
            else
                customers[i].dinner = false;
            cout << "Do you need parking space? y/n: ";
            cin >> answer;
            if (answer == "y")
            {
                customers[i].parking = true;
                for (int j = 0; j < parkings.size(); j++)
                {
                    if (parkings[j].booked == false)
                    {
                        park = j;
                        break;
                    }
                }
            }
            else
                customers[i].parking = false;
            x = i;
            debug = true;
            }
        }
    if(debug == false)
    {
        cout << "There is no such customer." << endl;
    }
    if (customers[x].parking == true)
    {
        parkings[park].booked == true;
        customers[x].parking_id = parkings[park].parking_space_id;
    }

    for (int i = 0; i < rooms.size(); i++)
    {
        if (rooms[i].booked == false)
        {
            y = i;
            rom = true;
        }
    }
    if (rom == true)
    {
        rooms[y].booked = true;
        customers[x].room_id = rooms[y].room_id;
        rooms[y].customer_first_name = customers[x].first_name;
        rooms[y].customer_last_name = customers[x].last_name;  
    }
    else
    {
        cout << "There is no available room." << endl;
    }
    s.customers = customers;
    s.rooms = rooms;
    s.parkings = parkings;
    return s;
}



void HotelManagement::employeeReport(vector <Employee> employees)
{
    for (int i = 0; i < employees.size(); i++)
    {
        employees[i].getInformation();
    }
}

void HotelManagement::getAvailRooms(vector <Room> rooms)
{
    cout << "Today's free rooms: " << endl;
    for (int i = 0; i < rooms.size(); i++)
    {
        if (rooms[i].booked == false)
        {
            rooms[i].getInformation();
        }
    }

}

const int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int countLeapYears(Date d)
{
    int years = d.year;
    if (d.month <= 2)
        years--;
    return years / 4 - years / 100 + years / 400;
}

int getDifference(Date dt1, Date dt2)
{
    long int n1 = dt1.year * 365 + dt1.day;
 
    for (int i = 0; i < dt1.month - 1; i++)
        n1 += monthDays[i];
 
    n1 += countLeapYears(dt1);
 
    long int n2 = dt2.year * 365 + dt2.day;
    for (int i = 0; i < dt2.month - 1; i++)
        n2 += monthDays[i];
    n2 += countLeapYears(dt2);
    return (n2 - n1);
}

int HotelManagement::generateBill(vector <Customer> customers, vector <Room> rooms, vector <Parking> parkings)
{
    string a,b;
    bool name = false;
    int x, room_price, parking_price, dinner_price, breakfast_price;
    parking_price = 0;
    dinner_price = 0;
    breakfast_price = 0;
    cout << "Enter first name of the customer you want to generate bill for: ";
    cin >> a;
    cout << "Enter last name of the customer you want to generate bill for: ";
    cin >> b;   
    for (int i = 0; i < customers.size(); i++)
    {
        if (customers[i].first_name == a && customers[i].last_name == b)
        {
            x = i;
            name = true;
            break;
        }
    }
    if(name == true)
    {
        int days = getDifference(customers[x].from_date, customers[x].to_date);
        for (int i = 0; i < rooms.size(); i++)
        {
            if (rooms[i].room_id == customers[x].room_id)
            {
                room_price = rooms[i].rent_per_night;
                break;
            }
        }
        if (customers[x].parking == true)
        {
            for (int i = 0; i < parkings.size(); i++)
            {
                if(customers[x].parking_id == parkings[i].parking_space_id)
                {
                    parking_price = parkings[i].rent_for_parking_space;
                    break;
                }
            }
        }
        if (customers[x].breakfast == true)
            breakfast_price = 30;
        if (customers[x].dinner == true)
            dinner_price = 50;
        cout << "Price for room: " << days << "*" << room_price << endl;
        cout << "Price for parking space: " << days << "*" << parking_price << endl;
        cout << "Price for breakfast: " << days << "*" << breakfast_price << endl;
        cout << "Price for dinner: " << days << "*" << dinner_price << endl;
        int total = days*(room_price+parking_price+breakfast_price+dinner_price);
        cout << "Total: " << total << endl;
        return total;
    }
    else
    {
        cout << "There is no such customer" << endl;
        return 0;
    }
    
}

void HotelManagement::findCurrentCustomers(vector <Customer> customers)
{
    time_t t = time(0);
    tm * now = localtime(&t);
    cout << "Customers currently staying at the hotel: " << endl;
    for (int i = 0; i < customers.size(); i++)
    {
        if(customers[i].from_date.year <= now->tm_year + 1900 && customers[i].to_date.year >= now->tm_year + 1900 && customers[i].from_date.month <= now->tm_mon + 1 && customers[i].to_date.month >= now->tm_mon +1 && customers[i].from_date.day <= now->tm_mday && customers[i].to_date.day >= now->tm_mday)
        {
            customers[i].getInformation();
        }
    }
}

void HotelManagement::dayFinanceReport(vector <Customer> customers, vector <Room> rooms, vector <Parking> parkings)
{
    time_t t = time(0);
    tm * now = localtime(&t);
    int room_price = 0;
    int total = 0;
    int parking_price = 0;
    int breakfast_price = 0;
    int dinner_price = 0;
    int total_for_customer;
    for (int i = 0; i < customers.size(); i++)
    {
        if(customers[i].from_date.day == now->tm_mday)
        {
            total_for_customer = 0;
            int days = getDifference(customers[i].from_date, customers[i].to_date);
            for (int j = 0; j < rooms.size(); j++)
            {
                if (rooms[j].room_id == customers[i].room_id)
                {
                    room_price = rooms[j].rent_per_night;
                    break;
                }
            }
            if (customers[i].parking == true)
            {
                for (int j = 0; j < parkings.size(); j++)
                {
                    if(customers[i].parking_id == parkings[j].parking_space_id)
                    {
                        parking_price = parkings[j].rent_for_parking_space;
                        break;
                    }
                }
            }
            if (customers[i].breakfast == true)
                breakfast_price = 30;
            if (customers[i].dinner == true)
                dinner_price = 50;
            total_for_customer = days*(room_price+parking_price+breakfast_price+dinner_price);
            total += total_for_customer;
        }
    }
    cout << "Income of the day " << now->tm_mday << "." << now->tm_mon + 1 << "." << now->tm_year + 1900 << ": " << total << endl;

}


void HotelManagement::monthFinanceReport(vector <Customer> customers, vector <Room> rooms, vector <Parking> parkings)
{
    time_t t = time(0);
    tm * now = localtime(&t);
    int room_price = 0;
    int total = 0;
    int parking_price = 0;
    int breakfast_price = 0;
    int dinner_price = 0;
    int total_for_customer;
    for (int i = 0; i < customers.size(); i++)
    {
        if(customers[i].from_date.month == now->tm_mon +1)
        {
            total_for_customer = 0;
            int days = getDifference(customers[i].from_date, customers[i].to_date);
            for (int j = 0; j < rooms.size(); j++)
            {
                if (rooms[j].room_id == customers[i].room_id)
                {
                    room_price = rooms[j].rent_per_night;
                    break;
                }
            }
            if (customers[i].parking == true)
            {
                for (int j = 0; j < parkings.size(); j++)
                {
                    if(customers[i].parking_id == parkings[j].parking_space_id)
                    {
                        parking_price = parkings[j].rent_for_parking_space;
                        break;
                    }
                }
            }
            if (customers[i].breakfast == true)
                breakfast_price = 30;
            if (customers[i].dinner == true)
                dinner_price = 50;
            total_for_customer = days*(room_price+parking_price+breakfast_price+dinner_price);
            total += total_for_customer;
        }
    }
    cout << "Income of the month " << now->tm_mon + 1 << "." << now->tm_year + 1900 << ": " << total << endl;

}

void HotelManagement::yearFinanceReport(vector <Customer> customers, vector <Room> rooms, vector <Parking> parkings)
{
    time_t t = time(0);
    tm * now = localtime(&t);
    int room_price = 0;
    int total = 0;
    int parking_price = 0;
    int breakfast_price = 0;
    int dinner_price = 0;
    int total_for_customer;
    for (int i = 0; i < customers.size(); i++)
    {
        if(customers[i].from_date.year == now->tm_year + 1900)
        {
            total_for_customer = 0;
            int days = getDifference(customers[i].from_date, customers[i].to_date);
            for (int j = 0; j < rooms.size(); j++)
            {
                if (rooms[j].room_id == customers[i].room_id)
                {
                    room_price = rooms[j].rent_per_night;
                    break;
                }
            }
            if (customers[i].parking == true)
            {
                for (int j = 0; j < parkings.size(); j++)
                {
                    if(customers[i].parking_id == parkings[j].parking_space_id)
                    {
                        parking_price = parkings[j].rent_for_parking_space;
                        break;
                    }
                }
            }
            if (customers[i].breakfast == true)
                breakfast_price = 30;
            if (customers[i].dinner == true)
                dinner_price = 50;
            total_for_customer = days*(room_price+parking_price+breakfast_price+dinner_price);
            total += total_for_customer;
        }
    }
    cout << "Income of the year " << now->tm_year + 1900 << ": " << total << endl;

}

