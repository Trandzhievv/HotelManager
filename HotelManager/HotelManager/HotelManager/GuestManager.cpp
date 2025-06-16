#include "GuestManager.h"
#include <iostream>

void GuestManager::addGuest(const Guest& guest) {
    guests.pushBack(guest);
}

const Guest* GuestManager::getGuestById(unsigned id) const {
    for (size_t i = 0; i < guests.getSize(); ++i) {
        if (guests[i].getId() == id)
            return &guests[i];
    }
    return nullptr;
}

bool GuestManager::exists(unsigned id) const {
    return getGuestById(id) != nullptr;
}

const Guest& GuestManager::getAt(int index) const
{
    if (index < 0 || index >= guests.getSize()) {
        throw std::out_of_range("Invalid index in GuestManager::getAt");
    }

    return guests[index];
}

void GuestManager::printAllGuests() const {
    for (size_t i = 0; i < guests.getSize(); ++i) {
        guests[i].print();
        std::cout << "------------------\n";
    }
}

int GuestManager::getCount() const {
    return guests.getSize();
}

Guest* GuestManager::getById(unsigned id) {
    for (int i = 0; i < guests.getSize(); ++i) {
        if (guests[i].getId() == id)
            return &guests[i];
    }
    return nullptr;
}

