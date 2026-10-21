#ifndef BOOKING_LIST_H
#define BOOKING_LIST_H

#include "ticket.h"

struct BookingNode {
    Ticket* ticket;
    BookingNode* next;
};

class BookingList {
private:
    BookingNode* head;

public:
    BookingList();
    ~BookingList();

    void add(Ticket* ticket);
    Ticket* search(int ticketId);
    void display();
};

#endif
