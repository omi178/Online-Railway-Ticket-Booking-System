#include "train.h"

Train::Train(int n, string nm, string s, string d, int totalSeats, float f)
    : seats(totalSeats) {
    number = n;
    name = nm;
    source = s;
    destination = d;
    fare = f;
}

int Train::getNumber() {
    return number;
}

float Train::getFare() {
    return fare;
}

SeatMap& Train::getSeats() {
    return seats;
}

void Train::display() {
    cout << number << " | " << name << " | "
         << source << " -> " << destination
         << " | Seats: " << seats.countFree() << "/" << seats.getTotal()
         << " | Fare: " << fare << "\n";
}

TrainList::TrainList() {
    count = 0;
}

TrainList::~TrainList() {
    for (int i = 0; i < count; i++)
        delete trains[i];
}

bool TrainList::addTrain(Train* train) {
    if (count >= MAX_TRAINS)
        return false;

    trains[count] = train;
    count++;
    return true;
}

Train* TrainList::find(int number) {
    for (int i = 0; i < count; i++) {
        if (trains[i]->getNumber() == number)
            return trains[i];
    }
    return NULL;
}

void TrainList::display() {
    if (count == 0) {
        cout << "No trains available.\n";
        return;
    }

    for (int i = 0; i < count; i++)
        trains[i]->display();
}
