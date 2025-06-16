#pragma once
#include "Room.h"
#include "RoomFactory.h"

class RoomCollection {
private:
    Room** rooms;
    int size;
    int capacity;

    void resize(int newCapacity);
    void copyFrom(const RoomCollection& other);
    void moveFrom(RoomCollection&& other);
    void free();

public:
    RoomCollection();
    RoomCollection(const RoomCollection& other);
    RoomCollection& operator=(const RoomCollection& other);
    RoomCollection(RoomCollection&& other) noexcept;
    RoomCollection& operator=(RoomCollection&& other) noexcept;
    ~RoomCollection();

    void add(const Room& room);
    void add(RoomType type, int id, double basePrice);

    Room* getRoomAt(int index);

    void printAll() const;
    int getSize() const;
};

