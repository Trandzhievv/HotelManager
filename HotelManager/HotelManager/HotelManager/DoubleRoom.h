#pragma once
#include "Room.h"

class DoubleRoom : public Room {
public:
    DoubleRoom(int id, double basePrice);

    double calculatePrice() const override;
    MyString getTypeStr() const override;
    RoomType getRoomType() const override;
    Room* clone() const override;
};

