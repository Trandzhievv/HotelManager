#include "ConferenceRoom.h"

ConferenceRoom::ConferenceRoom(int id, double basePrice)
    : Room(id, basePrice) {
}

double ConferenceRoom::calculatePrice() const {
    return getBasePrice() * 2.0;
}

MyString ConferenceRoom::getTypeStr() const {
    return MyString("Conference");
}

RoomType ConferenceRoom::getRoomType() const {
    return RoomType::CONFERENCE;
}

Room* ConferenceRoom::clone() const {
    return new ConferenceRoom(*this);
}
