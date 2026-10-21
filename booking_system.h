#ifndef BOOKING_SYSTEM_H
#define BOOKING_SYSTEM_H

#include "train.h"
#include "ticket.h"
#include "booking_list.h"

class BookingSystem {
private:
    TrainList trains;
    BookingList bookings;
    Payment payment;
    int nextTicketId;
    int nextPassengerId;

    Ticket* createTicket(string name, int age, Train* train, int seat, int type);

public:
    BookingSystem();

    void showTrains();
    void addTrain();
    void showSeats();
    void bookTicket();
    void showBookings();
    void searchTicket();
};

#endif
