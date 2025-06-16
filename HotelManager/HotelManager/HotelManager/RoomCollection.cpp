#include "RoomCollection.h"
#include <iostream>
#pragma warning(disable: 6386)

void RoomCollection::resize(int newCapacity) {
    Room** temp = new Room * [newCapacity];
    for (int i = 0; i < size; ++i) {
        temp[i] = rooms[i];
    }

    delete[] rooms;
    rooms = temp;
    capacity = newCapacity;
}

void RoomCollection::copyFrom(const RoomCollection& other) {
    rooms = new Room * [other.capacity];
    for (int i = 0; i < other.size; ++i) {
        rooms[i] = other.rooms[i]->clone();
    }
    size = other.size;
    capacity = other.capacity;
}

void RoomCollection::moveFrom(RoomCollection&& other) {
    rooms = other.rooms;
    size = other.size;
    capacity = other.capacity;
    other.rooms = nullptr;
    other.size = 0;
    other.capacity = 0;
}

void RoomCollection::free() {
    for (int i = 0; i < size; ++i) {
        delete rooms[i];
    }
    delete[] rooms;
}

RoomCollection::RoomCollection() : size(0), capacity(8) {
    rooms = new Room * [capacity];
}

RoomCollection::RoomCollection(const RoomCollection& other) {
    copyFrom(other);
}

RoomCollection& RoomCollection::operator=(const RoomCollection& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

RoomCollection::RoomCollection(RoomCollection&& other) noexcept {
    moveFrom(std::move(other));
}

RoomCollection& RoomCollection::operator=(RoomCollection&& other) noexcept {
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

RoomCollection::~RoomCollection() {
    free();
}

void RoomCollection::add(const Room& room) {
    if (size == capacity) {
        resize(capacity * 2);
    }
    rooms[size++] = room.clone();
}

void RoomCollection::add(RoomType type, int id, double basePrice) {
    if (size == capacity) {
        resize(capacity * 2);
    }
    rooms[size++] = RoomFactory::create(type, id, basePrice);
}

Room* RoomCollection::getRoomAt(int index)
{
    if (index >= 0 && index < size)
        return rooms[index];

    return nullptr;
}

void RoomCollection::printAll() const {
    for (int i = 0; i < size; ++i) {
        std::cout << rooms[i]->getTypeStr().getString()
            << " | Price: " << rooms[i]->calculatePrice() << "\n";
    }
}

int RoomCollection::getSize() const {
    return size;
}

