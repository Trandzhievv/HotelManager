#pragma once
#include "Room.h"

class LuxuryRoom : public Room {
public:
    LuxuryRoom(int id, double basePrice);

    double calculatePrice() const override;
    MyString getTypeStr() const override;
    RoomType getRoomType() const override;
    Room* clone() const override;
};

