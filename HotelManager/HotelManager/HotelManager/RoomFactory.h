#pragma once
#include "Room.h"
#include "RoomType.h"
#include "SingleRoom.h"
#include "DoubleRoom.h"
#include "LuxuryRoom.h"
#include "ConferenceRoom.h"
#include "ApartmentRoom.h"

class RoomFactory {
public:
    static Room* create(RoomType type, int id, double basePrice);
};

