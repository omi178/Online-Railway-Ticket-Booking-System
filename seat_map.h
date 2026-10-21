#ifndef SEAT_MAP_H
#define SEAT_MAP_H

#define MAX_SEATS 20

class SeatMap {
private:
    int seats[MAX_SEATS + 1];
    int total;

public:
    SeatMap();
    SeatMap(int totalSeats);

    int allocate();
    int countFree();
    int getTotal();
    void display();
};

#endif
