#include "LuxuryRoom.h"

LuxuryRoom::LuxuryRoom(int id, double basePrice)
    : Room(id, basePrice) {
}

double LuxuryRoom::calculatePrice() const {
    return getBasePrice() * 1.5;
}

MyString LuxuryRoom::getTypeStr() const {
    return MyString("Luxury");
}

RoomType LuxuryRoom::getRoomType() const {
    return RoomType::LUXURY;
}

Room* LuxuryRoom::clone() const {
    return new LuxuryRoom(*this);
}
