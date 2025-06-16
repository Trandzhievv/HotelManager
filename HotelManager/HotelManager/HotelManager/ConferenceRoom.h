#pragma once
#include "Room.h"

class ConferenceRoom : public Room {
public:
    ConferenceRoom(int id, double basePrice);

    double calculatePrice() const override;
    MyString getTypeStr() const override;
    RoomType getRoomType() const override;
    Room* clone() const override;
};


