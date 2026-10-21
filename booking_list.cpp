#include <iostream>
#include "booking_list.h"
using namespace std;

BookingList::BookingList() {
    head = NULL;
}

BookingList::~BookingList() {
    while (head != NULL) {
        BookingNode* temp = head;
        head = head->next;
        delete temp->ticket;
        delete temp;
    }
}

void BookingList::add(Ticket* ticket) {
    BookingNode* node = new BookingNode;
    node->ticket = ticket;
    node->next = NULL;

    if (head == NULL) {
        head = node;
        return;
    }

    BookingNode* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = node;
}

Ticket* BookingList::search(int ticketId) {
    BookingNode* temp = head;

    while (temp != NULL) {
        if (temp->ticket->getId() == ticketId)
            return temp->ticket;

        temp = temp->next;
    }

    return NULL;
}

void BookingList::display() {
    if (head == NULL) {
        cout << "No bookings.\n";
        return;
    }

    BookingNode* temp = head;

    while (temp != NULL) {
        temp->ticket->display();
        temp = temp->next;
    }
}
