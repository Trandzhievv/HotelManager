#include "HotelSystem.h"
#include "RoomCollection.h"
#include "Reservation.h"
#include <iostream>
#include <fstream>

void HotelSystem::addRoom(RoomType type, int id, double basePrice) {
    rooms.add(type, id, basePrice);
}

void HotelSystem::printAllRooms() const {
    rooms.printAll();
}

void HotelSystem::addGuest(const MyString& name, const MyString& phone, const MyString& email, unsigned id, GuestType type) {
    guests.addGuest(Guest(name, phone, email, id, type));
}

void HotelSystem::checkAndUpdateGuestType(unsigned guestId)
{
    int count = 0;
    for (int i = 0; i < reservations.getSize(); ++i) {
        const Reservation& r = reservations[i];
        if (r.getGuest() && r.getGuest()->getId() == guestId)
            count++;
    }

    Guest* g = guests.getById(guestId);
    if (!g) return;

    if (count >= 5)
        g->setType(GuestType::PLATINUM);
    else if (count >= 3)
        g->setType(GuestType::GOLD);
}

void HotelSystem::printAllGuests() const {
    guests.printAllGuests();
}

bool HotelSystem::makeReservation(unsigned guestId, int roomId, unsigned startDay, unsigned endDay) {
    const Guest* guest = guests.getGuestById(guestId);
    Room* room = nullptr;

    for (int i = 0; i < rooms.getSize(); ++i) {
        Room* r = rooms.getRoomAt(i);
        if (r && r->getId() == roomId) {
            room = r;
            break;
        }
    }


    if (!guest || !room) {
        std::cout << "Invalid guest or room.\n";
        return false;
    }

    reservations.pushBack(Reservation(room, guest, startDay, endDay));
    std::cout << "Reservation created successfully.\n";

    checkAndUpdateGuestType(guestId);

    return true;
}

void HotelSystem::printAllReservations() const {
    for (size_t i = 0; i < reservations.getSize(); ++i) {
        reservations[i].print();
        std::cout << "----------------------\n";
    }
}

Room* HotelSystem::getRoomAt(int index) {
    return rooms.getRoomAt(index);
}

Room* HotelSystem::getRoomById(int id) {
    for (int i = 0; i < rooms.getSize(); ++i) {
        Room* r = rooms.getRoomAt(i);
        if (r && r->getId() == id)
            return r;
    }
    return nullptr;
}

int HotelSystem::getRoomCount() const {
    return rooms.getSize();
}

const Guest& HotelSystem::getGuestAt(int index) const {
    return guests.getAt(index);
}

int HotelSystem::getGuestCount() const {
    return guests.getCount();
}

const Reservation& HotelSystem::getReservationAt(int index) const {
    return reservations[index];
}

int HotelSystem::getReservationCount() const {
    return reservations.getSize();
}

void HotelSystem::printReservationsByGuest(unsigned guestId) const {
    bool found = false;
    for (int i = 0; i < reservations.getSize(); ++i) {
        const Reservation& r = reservations[i];
        if (r.getGuest() && r.getGuest()->getId() == guestId) {
            std::cout << "Reservation for guest ID " << guestId << ": ";
            r.print();
            found = true;
        }
    }
    if (!found)
        std::cout << "No reservations found for guest ID " << guestId << ".\n";
}

void HotelSystem::printReservationsByRoom(int roomId) const {
    bool found = false;
    for (int i = 0; i < reservations.getSize(); ++i) {
        const Reservation& r = reservations[i];
        if (r.getRoom() && r.getRoom()->getId() == roomId) {
            std::cout << "Reservation for room ID " << roomId << ": ";
            r.print();
            found = true;
        }
    }
    if (!found)
        std::cout << "No reservations found for room ID " << roomId << ".\n";
}

void HotelSystem::printTopProfitableRooms() const
{
    struct ProfitEntry {
        int roomId;
        double totalRevenue = 0;
    };

    MyVector<ProfitEntry> profits;

    for (int i = 0; i < reservations.getSize(); ++i) {
        const Reservation& r = reservations[i];
        if (!r.getRoom()) continue;

        int id = r.getRoom()->getId();
        double price = r.getFinalPrice();

        bool found = false;
        for (int j = 0; j < profits.getSize(); ++j) {
            if (profits[j].roomId == id) {
                profits[j].totalRevenue += price;
                found = true;
                break;
            }
        }

        if (!found) {
            ProfitEntry entry;
            entry.roomId = id;
            entry.totalRevenue = price;
            profits.pushBack(entry);
        }
    }

    std::cout << "--- Най-печеливши стаи ---\n";
    for (int i = 0; i < profits.getSize(); ++i) {
        std::cout << "Стая ID: " << profits[i].roomId
            << ", Приход: " << profits[i].totalRevenue << " лв\n";
    }
}

void HotelSystem::generateReports() const
{
    const int ROOM_TYPE_COUNT = 5;
    double totalRevenue = 0;
    int totalReservations = reservations.getSize();
    double revenueByType[ROOM_TYPE_COUNT] = {};
    int reservationsByType[ROOM_TYPE_COUNT] = {};

    for (int i = 0; i < totalReservations; ++i) {
        const Reservation& res = reservations[i];
        double price = res.getFinalPrice();
        totalRevenue += price;

        Room* r = res.getRoom();
        if (r) {
            int type = static_cast<int>(r->getRoomType());
            revenueByType[type] += price;
            reservationsByType[type]++;
        }
    }

    std::cout << "--- Financial Report ---\n";
    std::cout << "Total revenue from reservations: " << totalRevenue << " BGN\n";
    std::cout << "Total number of reservations: " << totalReservations << "\n\n";

    std::cout << "Revenue by room type:\n";
    for (int i = 0; i < ROOM_TYPE_COUNT; ++i) {
        std::cout << "Type " << i << " - Revenue: " << revenueByType[i] << " BGN, Reservations: " << reservationsByType[i] << "\n";
    }

    std::ofstream out("report.txt");
    if (out.is_open()) {
        out << "--- Financial Report ---\n";
        out << "Total revenue from reservations: " << totalRevenue << " BGN\n";
        out << "Total number of reservations: " << totalReservations << "\n\n";
        out << "Revenue by room type:\n";
        for (int i = 0; i < ROOM_TYPE_COUNT; ++i) {
            out << "Type " << i << " - Revenue: " << revenueByType[i] << " BGN, Reservations: " << reservationsByType[i] << "\n";
        }
        out.close();
        std::cout << "Report saved to report.txt\n";
    }
    else {
        std::cout << "Error writing to report.txt\n";
    }
}

void HotelSystem::cancelReservation(unsigned index)
{
    if (index >= reservations.getSize()) {
        std::cout << "Invalid reservation index.\n";
        return;
    }
    reservations.erase(index);
    std::cout << "Reservation cancelled.\n";
}

