#include "Receptionist.h"

Receptionist::Receptionist(const MyString& username)
    : User(username) {}

bool Receptionist::can(const MyString& action) const {
    return action == "add_guest" ||
        action == "make_reservation" ||
        action == "view_guests" ||
        action == "view_rooms" ||
        action == "cancel_reservation";
}

MyString Receptionist::getRole() const {
    return MyString("Receptionist");
}

User* Receptionist::clone() const {
    return new Receptionist(*this);
}
