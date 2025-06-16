#include "Room.h"

Room::Room(int id, double basePrice)
    : id(id), basePrice(basePrice), status(RoomStatus::FREE) {
}

int Room::getId() const {
    return id;
}

double Room::getBasePrice() const {
    return basePrice;
}

RoomStatus Room::getStatus() const {
    return status;
}

void Room::setStatus(RoomStatus newStatus) {
    status = newStatus;
}

