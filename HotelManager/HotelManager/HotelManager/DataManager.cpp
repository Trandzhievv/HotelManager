#include "DataManager.h"
#include <fstream>
#include <iostream>

static void writeString(std::ofstream& out, const MyString& str) {
    size_t len = str.getSize();
    out.write((const char*)&len, sizeof(len));
    out.write(str.getString(), len);
}

static MyString readString(std::ifstream& in) {
    size_t len;
    in.read((char*)&len, sizeof(len));
    char* buffer = new char[len + 1];
    in.read(buffer, len);
    buffer[len] = '\0';
    MyString result(buffer);
    delete[] buffer;
    return result;
}

void DataManager::saveToFile(HotelSystem& system, const char* filename) {
    std::ofstream out(filename, std::ios::binary);
    if (!out) {
        std::cout << "Error opening file for writing.\n";
        return;
    }

    int roomCount = system.getRoomCount();
    out.write((const char*)&roomCount, sizeof(roomCount));

    for (int i = 0; i < roomCount; ++i) {
        Room* r = system.getRoomAt(i);

        int type = static_cast<int>(r->getRoomType());
        int id = r->getId();
        double basePrice = r->getBasePrice();
        int status = static_cast<int>(r->getStatus());

        out.write((const char*)&type, sizeof(type));
        out.write((const char*)&id, sizeof(id));
        out.write((const char*)&basePrice, sizeof(basePrice));
        out.write((const char*)&status, sizeof(status));
    }

    int guestCount = system.getGuestCount();
    out.write((const char*)&guestCount, sizeof(guestCount));

    for (int i = 0; i < guestCount; ++i) {
       const Guest& g = system.getGuestAt(i); 

        int id = g.getId();
        int type = static_cast<int>(g.getType());

        out.write((const char*)&id, sizeof(id));
        writeString(out, g.getName());
        writeString(out, g.getPhone());
        writeString(out, g.getEmail());
        out.write((const char*)&type, sizeof(type));
    }

    int resCount = system.getReservationCount();
    out.write((const char*)&resCount, sizeof(resCount));

    for (int i = 0; i < resCount; ++i) {
       const Reservation& r = system.getReservationAt(i); 

        int guestId = r.getGuest()->getId();
        int roomId = r.getRoom()->getId();
        unsigned start = r.getStartDay();
        unsigned end = r.getEndDay();

        out.write((const char*)&guestId, sizeof(guestId));
        out.write((const char*)&roomId, sizeof(roomId));
        out.write((const char*)&start, sizeof(start));
        out.write((const char*)&end, sizeof(end));
    }

    out.close();
    std::cout << "Data saved to binary file.\n";
}

void DataManager::loadFromFile(HotelSystem& system, const char* filename) {
    std::ifstream in(filename, std::ios::binary);
    if (!in) {
        std::cout << "No save file found.\n";
        return;
    }

    int roomCount;
    in.read((char*)&roomCount, sizeof(roomCount));

    for (int i = 0; i < roomCount; ++i) {
        int type, id, status;
        double price;

        in.read((char*)&type, sizeof(type));
        in.read((char*)&id, sizeof(id));
        in.read((char*)&price, sizeof(price));
        in.read((char*)&status, sizeof(status));

        system.addRoom(static_cast<RoomType>(type), id, price);
        Room* r = system.getRoomById(id);
        if (r) r->setStatus(static_cast<RoomStatus>(status));
    }

    int guestCount;
    in.read((char*)&guestCount, sizeof(guestCount));

    for (int i = 0; i < guestCount; ++i) {
        int id, type;

        in.read((char*)&id, sizeof(id));

        MyString name = readString(in);
        MyString phone = readString(in);
        MyString email = readString(in);

        in.read((char*)&type, sizeof(type));

        system.addGuest(name, phone, email, id, static_cast<GuestType>(type));
    }


    int resCount;
    in.read((char*)&resCount, sizeof(resCount));

    for (int i = 0; i < resCount; ++i) {
        int guestId, roomId;
        unsigned start, end;

        in.read((char*)&guestId, sizeof(guestId));
        in.read((char*)&roomId, sizeof(roomId));
        in.read((char*)&start, sizeof(start));
        in.read((char*)&end, sizeof(end));

        system.makeReservation(guestId, roomId, start, end);
    }

    in.close();
    std::cout << "Data loaded from binary file.\n";
}
