#include <iostream>
#include "booking_system.h"
using namespace std;

BookingSystem::BookingSystem() {
    nextTicketId = 1001;
    nextPassengerId = 1;

    trains.addTrain(new Train(12951, "Mumbai Rajdhani", "Mumbai", "Delhi", 3, 1850));
    trains.addTrain(new Train(12009, "Shatabdi Express", "Mumbai", "Ahmedabad", 2, 920));
    trains.addTrain(new Train(12627, "Karnataka Express", "Bengaluru", "Delhi", 4, 1450));
}

Ticket* BookingSystem::createTicket(string name, int age, Train* train, int seat, int type) {
    Passenger passenger(nextPassengerId, name, age);
    nextPassengerId++;

    Ticket* ticket;

    if (type == 2)
        ticket = new ACTicket(nextTicketId, passenger, train->getNumber(), seat, train->getFare());
    else
        ticket = new GeneralTicket(nextTicketId, passenger, train->getNumber(), seat, train->getFare());

    nextTicketId++;
    return ticket;
}

void BookingSystem::showTrains() {
    trains.display();
}

void BookingSystem::addTrain() {
    int number, seats;
    float fare;
    string name, source, destination;

    cout << "Train number: ";
    cin >> number;

    if (trains.find(number) != NULL) {
        cout << "Train already exists.\n";
        return;
    }

    cout << "Train name: ";
    cin >> ws;
    getline(cin, name);

    cout << "Source: ";
    getline(cin, source);

    cout << "Destination: ";
    getline(cin, destination);

    cout << "Number of seats (1-" << MAX_SEATS << "): ";
    cin >> seats;

    if (seats < 1 || seats > MAX_SEATS) {
        cout << "Invalid number of seats.\n";
        return;
    }

    cout << "Fare: ";
    cin >> fare;

    if (trains.addTrain(new Train(number, name, source, destination, seats, fare)))
        cout << "Train added successfully.\n";
    else
        cout << "Train list is full.\n";
}

void BookingSystem::showSeats() {
    int number;
    cout << "Enter train number: ";
    cin >> number;

    Train* train = trains.find(number);

    if (train == NULL) {
        cout << "Train not found.\n";
        return;
    }

    train->getSeats().display();
    cout << "Free seats: " << train->getSeats().countFree()
         << "/" << train->getSeats().getTotal() << "\n";
}

void BookingSystem::bookTicket() {
    int number, age, type;
    string name;

    trains.display();

    cout << "Enter train number: ";
    cin >> number;

    Train* train = trains.find(number);

    if (train == NULL) {
        cout << "Train not found.\n";
        return;
    }

    if (train->getSeats().countFree() == 0) {
        cout << "No seats available on this train.\n";
        return;
    }

    cout << "Passenger name: ";
    cin >> ws;
    getline(cin, name);

    cout << "Age: ";
    cin >> age;

    cout << "1. General\n2. AC\nChoose type: ";
    cin >> type;

    int seat = train->getSeats().allocate();

    Ticket* ticket = createTicket(name, age, train, seat, type);
    bookings.add(ticket);

    cout << "\nTicket booked successfully!\n";
    payment.pay(ticket);
}

void BookingSystem::showBookings() {
    bookings.display();
}

void BookingSystem::searchTicket() {
    int id;
    cout << "Enter ticket ID: ";
    cin >> id;

    Ticket* ticket = bookings.search(id);

    if (ticket == NULL)
        cout << "Ticket not found.\n";
    else
        ticket->display();
}
