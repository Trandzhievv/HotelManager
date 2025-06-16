#include "HotelUI.h"
#include <iostream>

void HotelUI::run(HotelSystem& system, User* user) {
    MyString role = user->getRole();
    std::cout << "Logged in as: " << role.getString() << "\n";

    int choice;
    while (true) {
        std::cout << "\n[Main Menu]\n";

        if (user->can("add_guest"))
            std::cout << "1. Add Guest\n";
        if (user->can("make_reservation"))
            std::cout << "2. Make Reservation\n";
        if (user->can("view_guests"))
            std::cout << "3. View Guests\n";
        if (user->can("view_rooms"))
            std::cout << "4. View Rooms\n";
        if (user->can("view_reservations"))
            std::cout << "5. View Reservations\n";
        if (user->can("save_data"))
            std::cout << "6. Save to file\n";
        if (user->can("load_data"))
            std::cout << "7. Load from file\n";
        if (user->can("view_reservations")) {
            std::cout << "8. View reservations by Guest ID\n";
            std::cout << "9. View reservations by Room ID\n";
        }
        if (user->can("view_financials")) { 
            std::cout << "10. Most profitable rooms\n";
            std::cout << "11. Financial reports\n";
        }
        if (user->can("cancel_reservation"))
            std::cout << "12. Cancel reservation\n";

        std::cout << "0. Log out\nChoice: ";
        std::cin >> choice;

        if (choice == 0) break;

        switch (choice) {
        case 1:
            if (!user->can("add_guest")) break;
            {
                MyString name, phone, email;
                unsigned id;
                int typeInt;

                std::cout << "Name: "; std::cin >> name;
                std::cout << "Phone: "; std::cin >> phone;
                std::cout << "Email: "; std::cin >> email;
                std::cout << "ID: "; std::cin >> id;
                std::cout << "Guest type (0-Regular, 1-Gold, 2-Platinum): ";
                std::cin >> typeInt;

                system.addGuest(name, phone, email, id, static_cast<GuestType>(typeInt));
            }
            break;

        case 2:
            if (!user->can("make_reservation")) break;
            {
                unsigned guestId, start, end;
                int roomId;
                std::cout << "Guest ID: "; std::cin >> guestId;
                std::cout << "Room ID: "; std::cin >> roomId;
                std::cout << "Start Day: "; std::cin >> start;
                std::cout << "End Day: "; std::cin >> end;

                system.makeReservation(guestId, roomId, start, end);
            }
            break;

        case 3:
            if (user->can("view_guests"))
                system.printAllGuests();
            break;

        case 4:
            if (user->can("view_rooms"))
                system.printAllRooms();
            break;

        case 5:
            if (user->can("view_reservations"))
                system.printAllReservations();
            break;

        case 6:
            if (!user->can("save_data")) {
                std::cout << "Access denied.\n";
                break;
            }
            DataManager::saveToFile(system, "hotel_data.bin");
            break;

        case 7:
            if (!user->can("load_data")) {
                std::cout << "Access denied.\n";
                break;
            }
            DataManager::loadFromFile(system, "hotel_data.bin");
            break;

        case 8:
            if (!user->can("view_reservations")) break;
            {
                unsigned guestId;
                std::cout << "Enter Guest ID: ";
                std::cin >> guestId;
                system.printReservationsByGuest(guestId);
            }
            break;

        case 9:
            if (!user->can("view_reservations")) break;
            {
                int roomId;
                std::cout << "Enter Room ID: ";
                std::cin >> roomId;
                system.printReservationsByRoom(roomId);
            }
            break;

        case 10:
            if (!user->can("view_financials")) break; 
            system.printTopProfitableRooms();
            break;

        case 11:
            if (!user->can("view_financials")) break;
            system.generateReports();
            break;
        case 12:
            if (!user->can("cancel_reservation")) break;
            {
                system.printAllReservations(); 
                std::cout << "Enter index of reservation to cancel: ";
                unsigned index;
                std::cin >> index;
                system.cancelReservation(index);
            }
            break;

        default:
            std::cout << "Invalid choice or access denied.\n";
        }
    }
}
