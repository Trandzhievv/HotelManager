#pragma once
#include "Room.h"

class SingleRoom : public Room {
public:
    SingleRoom(int id, double basePrice);

    double calculatePrice() const override;
    MyString getTypeStr() const override;
    RoomType getRoomType() const override;

    Room* clone() const override;
};


