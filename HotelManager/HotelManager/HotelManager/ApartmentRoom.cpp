#include "ApartmentRoom.h"

ApartmentRoom::ApartmentRoom(int id, double basePrice)
    : Room(id, basePrice) {
}

double ApartmentRoom::calculatePrice() const {
    return getBasePrice() * 1.8;
}

MyString ApartmentRoom::getTypeStr() const {
    return MyString("Apartment");
}

RoomType ApartmentRoom::getRoomType() const {
    return RoomType::APARTMENT;
}

Room* ApartmentRoom::clone() const {
    return new ApartmentRoom(*this);
}

