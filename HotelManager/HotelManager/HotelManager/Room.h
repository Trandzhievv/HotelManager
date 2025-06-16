#pragma once
#include "MyString.h"
#include "RoomType.h"

enum class RoomStatus {
    FREE,
    RESERVED,
    UNDER_MAINTENANCE
};

class Room {
private:
    int id;
    double basePrice;
    RoomStatus status;

public:
    Room(int id, double basePrice);
    virtual ~Room() = default;

    int getId() const;
    double getBasePrice() const;
    RoomStatus getStatus() const;
    void setStatus(RoomStatus newStatus);

    virtual double calculatePrice() const = 0;
    virtual MyString getTypeStr() const = 0;
    virtual RoomType getRoomType() const = 0;

    virtual Room* clone() const = 0;
};


