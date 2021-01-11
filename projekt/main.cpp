#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <tuple>
#include "Person.h"
#include "Employee.h"
#include "Customer.h"
#include "Parking.h"
#include "Room.h"
#include "HotelManagement.h"
using namespace std;

int main()
{
    Result s;
    vector <Employee> employees;
    Employee employee1("Anna", "Nowak", 2500, employees);
    employees.push_back(employee1);
    Employee employee2("Jan", "Nowak", 2500, employees);
    employees.push_back(employee2);
    Employee employee3("Jan", "Kowalski", 2500, employees);
    employees.push_back(employee3);
    
    vector <Customer> customers;
    Customer customer1("Julia", "Toklowicz", "123456789", customers);
    customers.push_back(customer1);
    Customer customer2("Mateusz", "Janczak", "263548173", customers);
    customers.push_back(customer2);
    Customer customer3("Monika", "Kempinska", "635481625", customers);
    customers.push_back(customer3);
    Customer customer4("Jakub", "Kwiatkowski", "635273916", customers);
    customers.push_back(customer4);
    Customer customer5("Anna", "Nowak", "736294736", customers);
    customers.push_back(customer5);
   
    vector <Parking> parkings;
    Parking parking1(1, "regular", 50, parkings);
    parkings.push_back(parking1);
    Parking parking2(2, "regular", 50, parkings);
    parkings.push_back(parking2);
    Parking parking3(3, "regular", 50, parkings);
    parkings.push_back(parking3);
    Parking parking4(4, "regular", 50, parkings);
    parkings.push_back(parking4);
    Parking parking5(5, "regular", 50, parkings);
    parkings.push_back(parking5);
    
    vector <Room> rooms;
    Room room1(1, 140, "regular", rooms);
    rooms.push_back(room1);
    Room room2(2, 140, "regular", rooms);
    rooms.push_back(room2);
    Room room3(3, 140, "regular", rooms);
    rooms.push_back(room3);
    Room room4(4, 140, "regular", rooms);
    rooms.push_back(room4);
    Room room5(5, 140, "regular", rooms);
    rooms.push_back(room5);
   
    cout << "Menu: " << endl;
    cout << "1. Sort customers." << endl;
    cout << "2. Find customer." << endl;
    cout << "3. Sort parking spaces." << endl;
    cout << "4. Find parking space." << endl;
    cout << "5. Sort rooms." << endl;
    cout << "6. Find rooms." << endl;
    cout << "7. Make a guests report." << endl;
    cout << "8. Book a room." << endl;
    cout << "9. Get today's available rooms." << endl;
    cout << "10. Generate a bill for a customer." << endl;
    cout << "11. Find current customers." << endl;
    cout << "12. Make an employees report." << endl;
    cout << "13. Make day finance report." << endl;
    cout << "14. Make month finance report." << endl;
    cout << "15. Make year finance report." << endl;
    cout << "16. Exit." << endl;

    int x;
    string answer;
    HotelManagement hotel;
    cout << "Enter number from 1 to 16: ";
    cin >> x;
    while(x!= 16)
    {
        switch(x)
        {
            case 1:
                hotel.sortCustomers(customers);
                break;
            case 2:
                hotel.findCustomer(customers);
                break;
            case 3:
                hotel.sortParkingSpaces(parkings);
                break;
            case 4:
                hotel.findParkingSpace(parkings);
                break;
            case 5:
                hotel.sortRooms(rooms);
                break;
            case 6:
                hotel.findRoom(rooms);
                break;
            case 7:
                hotel.guestRaport(customers);
                break;
            case 8:
                s = hotel.bookRoom(customers, rooms, parkings);
                customers = s.customers;
                rooms = s.rooms;
                parkings = s.parkings;
                break;
            case 9:
                hotel.getAvailRooms(rooms);
                break;
            case 10:
                hotel.generateBill(customers, rooms, parkings);
                break;
            case 11:
                hotel.findCurrentCustomers(customers);
                break;
            case 12:
                hotel.employeeReport(employees);
                break;
            case 13:
                hotel.dayFinanceReport(customers, rooms, parkings);
                break;
            case 14:
                hotel.monthFinanceReport(customers, rooms, parkings);
                break;
            case 15:
                hotel.yearFinanceReport(customers, rooms, parkings);
                break;
            case 16:
                break;
            default:
                cout << "Invalid number." << endl;
        }
        cout << "Enter number from 1 to 16: ";
        cin >> x;
    }
    return 0;
}