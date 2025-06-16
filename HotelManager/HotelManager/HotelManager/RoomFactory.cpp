#include "RoomFactory.h"

Room* RoomFactory::create(RoomType type, int id, double basePrice) {
    switch (type) {
    case RoomType::SINGLE:
        return new SingleRoom(id, basePrice);
    case RoomType::DOUBLE:
        return new DoubleRoom(id, basePrice);
    case RoomType::LUXURY:
        return new LuxuryRoom(id, basePrice);
    case RoomType::CONFERENCE:
        return new ConferenceRoom(id, basePrice);
    case RoomType::APARTMENT:
        return new ApartmentRoom(id, basePrice);
    default:
        return nullptr; 
    }
}

