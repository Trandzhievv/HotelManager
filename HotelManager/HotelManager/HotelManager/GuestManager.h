#pragma once
#include "Guest.h"
#include "MyVector.hpp"

class GuestManager {
private:
    MyVector<Guest> guests;

public:
    void addGuest(const Guest& guest);
    const Guest* getGuestById(unsigned id) const;
    void printAllGuests() const;
    bool exists(unsigned id) const;
    const Guest& getAt(int index) const;

    int getCount() const;
    Guest* getById(unsigned id);
};

