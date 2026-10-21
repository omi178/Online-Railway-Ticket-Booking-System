#include <iostream>
#include "booking_system.h"
using namespace std;

int main() {
    BookingSystem system;
    int choice;

    do {
        cout << "\nONLINE TICKET BOOKING SYSTEM\n";
        cout << "1. Show Trains\n";
        cout << "2. Add Train\n";
        cout << "3. Show Seats\n";
        cout << "4. Book Ticket\n";
        cout << "5. Show Bookings\n";
        cout << "6. Search Ticket\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: system.showTrains(); break;
            case 2: system.addTrain(); break;
            case 3: system.showSeats(); break;
            case 4: system.bookTicket(); break;
            case 5: system.showBookings(); break;
            case 6: system.searchTicket(); break;
            case 7: cout << "Thank you!\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 7);

    return 0;
}
