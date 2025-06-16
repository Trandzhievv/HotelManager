#pragma once
#include "Room.h"
#include "Guest.h"

class Reservation {
private:
    Room* room;
    const Guest* guest;
    unsigned startDay;
    unsigned endDay;
    double finalPrice;

public:
    Reservation();
    Reservation(Room* room, const Guest* guest, unsigned startDay, unsigned endDay);

    const Guest* getGuest() const;
    Room* getRoom() const;
    int getRoomId() const { return room ? room->getId() : -1; }
    unsigned getStartDay() const;
    unsigned getEndDay() const;
    unsigned getDuration() const { return endDay - startDay; }
    double getFinalPrice() const;

    void print() const;
};


