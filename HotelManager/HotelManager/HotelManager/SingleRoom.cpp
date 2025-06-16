#include "SingleRoom.h"

SingleRoom::SingleRoom(int id, double basePrice)
    : Room(id, basePrice) {
}

double SingleRoom::calculatePrice() const {
    return getBasePrice();
}

MyString SingleRoom::getTypeStr() const {
    return MyString("Single");
}

RoomType SingleRoom::getRoomType() const {
    return RoomType::SINGLE;
}

Room* SingleRoom::clone() const {
    return new SingleRoom(*this);
}

