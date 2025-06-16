#include "Manager.h"

Manager::Manager(const MyString& username)
    : User(username) {}

bool Manager::can(const MyString&) const {
    return true;
}

MyString Manager::getRole() const {
    return MyString("Manager");
}

User* Manager::clone() const {
    return new Manager(*this);
}

