#include "Accountant.h"

Accountant::Accountant(const MyString& username)
    : User(username) {}

bool Accountant::can(const MyString& action) const {
    return action == "view_reservations" || (action == "view_financials");
}

MyString Accountant::getRole() const {
    return MyString("Accountant");
}

User* Accountant::clone() const {
    return new Accountant(*this);
}
