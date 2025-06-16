#include "Reservation.h"
#include <iostream>

Reservation::Reservation(): 
    room(nullptr), guest(nullptr), startDay(0), endDay(0), finalPrice(0.0) {}

Reservation::Reservation(Room* room, const Guest* guest, unsigned startDay, unsigned endDay):
    room(room), guest(guest), startDay(startDay), endDay(endDay)
{
    unsigned duration = endDay - startDay + 1;
    double base = room->calculatePrice();
    double discount = guest->getDiscountPercent();

    finalPrice = duration * base * (1 - discount / 100.0);
}

const Guest* Reservation::getGuest() const {
    return guest;
}

Room* Reservation::getRoom() const {
    return room;
}

unsigned Reservation::getStartDay() const {
    return startDay;
}

unsigned Reservation::getEndDay() const {
    return endDay;
}

double Reservation::getFinalPrice() const {
    return finalPrice;
}

void Reservation::print() const 
{
    std::cout << "Reservation:\n"
        << "Room ID: " << room->getId() << " (" << room->getTypeStr().getString() << ")\n"
        << "Guest ID: " << guest->getId() << ", Name: " << guest->getName().getString() << "\n"
        << "Period: Day " << startDay << " to Day " << endDay << "\n"
        << "Total Price: " << finalPrice << "\n";
}
