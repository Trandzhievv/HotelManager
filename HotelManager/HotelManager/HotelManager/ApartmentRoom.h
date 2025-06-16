#pragma once
#include "Room.h"

class ApartmentRoom : public Room {
public:
    ApartmentRoom(int id, double basePrice);

    double calculatePrice() const override;
    MyString getTypeStr() const override;
    RoomType getRoomType() const override;
    Room* clone() const override;
};


