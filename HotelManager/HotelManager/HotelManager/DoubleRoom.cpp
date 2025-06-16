#include "DoubleRoom.h"

DoubleRoom::DoubleRoom(int id, double basePrice)
    : Room(id, basePrice) {
}

double DoubleRoom::calculatePrice() const {
    return getBasePrice() * 1.2;  
}

MyString DoubleRoom::getTypeStr() const {
    return MyString("Double");
}

RoomType DoubleRoom::getRoomType() const {
    return RoomType::DOUBLE;
}

Room* DoubleRoom::clone() const {
    return new DoubleRoom(*this);
}
