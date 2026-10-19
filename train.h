#ifndef TRAIN_H
#define TRAIN_H

#include <iostream>
#include <string>
#include "seat_map.h"
using namespace std;

#define MAX_TRAINS 10

class Train {
private:
    int number;
    string name;
    string source;
    string destination;
    float fare;
    SeatMap seats;

public:
    Train(int n, string nm, string s, string d, int totalSeats, float f);

    int getNumber();
    float getFare();
    SeatMap& getSeats();
    void display();
};

class TrainList {
private:
    Train* trains[MAX_TRAINS];
    int count;

public:
    TrainList();
    ~TrainList();

    bool addTrain(Train* train);
    Train* find(int number);
    void display();
};

#endif
