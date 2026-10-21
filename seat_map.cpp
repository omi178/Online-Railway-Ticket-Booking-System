#include <iostream>
#include "seat_map.h"
using namespace std;

SeatMap::SeatMap() {
    total = 0;
    for (int i = 0; i <= MAX_SEATS; i++)
        seats[i] = 0;
}

SeatMap::SeatMap(int totalSeats) {
    total = totalSeats;

    if (total > MAX_SEATS)
        total = MAX_SEATS;

    for (int i = 0; i <= MAX_SEATS; i++)
        seats[i] = 0;
}

int SeatMap::allocate() {
    for (int i = 1; i <= total; i++) {
        if (seats[i] == 0) {
            seats[i] = 1;
            return i;
        }
    }

    return 0;
}

int SeatMap::countFree() {
    int freeSeats = 0;

    for (int i = 1; i <= total; i++)
        if (seats[i] == 0)
            freeSeats++;

    return freeSeats;
}

int SeatMap::getTotal() {
    return total;
}

void SeatMap::display() {
    for (int i = 1; i <= total; i++) {
        if (seats[i] == 0)
            cout << "[" << i << ":Free] ";
        else
            cout << "[" << i << ":Booked] ";

        if (i % 5 == 0)
            cout << "\n";
    }

    cout << "\n";
}
