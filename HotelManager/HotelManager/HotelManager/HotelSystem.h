#pragma once
#include "RoomCollection.h"
#include "GuestManager.h"
#include "Reservation.h"
#include "MyVector.hpp"

class HotelSystem {
private:
    RoomCollection rooms;
    GuestManager guests;
    MyVector<Reservation> reservations;

public:
    void addRoom(RoomType type, int id, double basePrice);
    void printAllRooms() const;

    void addGuest(const MyString& name, const MyString& phone, const MyString& email, unsigned id, GuestType type);
    void checkAndUpdateGuestType(unsigned guestId);
    void printAllGuests() const;

    bool makeReservation(unsigned guestId, int roomId, unsigned startDay, unsigned endDay);
    void printAllReservations() const;

    Room* getRoomAt(int index);
    Room* getRoomById(int id);
    
    int getRoomCount() const;

    const Guest& getGuestAt(int index) const;
    int getGuestCount() const;

    const Reservation& getReservationAt(int index) const;
    int getReservationCount() const;

    void printReservationsByGuest(unsigned guestId) const;
    void printReservationsByRoom(int roomId) const;

    void printTopProfitableRooms() const;
    void generateReports() const;

    void cancelReservation(unsigned index);

};

