#include "Guest.h"
#include <iostream>

Guest::Guest() : id(0), type(GuestType::REGULAR) {}

Guest::Guest(const MyString& name, const MyString& phone, const MyString& email, unsigned id, GuestType type):
    name(name), phone(phone), email(email), id(id), type(type) {}

const MyString& Guest::getName() const {
    return name;
}

const MyString& Guest::getPhone() const {
    return phone;
}

const MyString& Guest::getEmail() const {
    return email;
}

unsigned Guest::getId() const {
    return id;
}

GuestType Guest::getType() const {
    return type;
}

double Guest::getDiscountPercent() const {
    switch (type) {
    case GuestType::REGULAR:  return 0.0;
    case GuestType::GOLD:     return 10.0;
    case GuestType::PLATINUM: return 15.0;
    default:                  return 0.0;
    }
}

void Guest::setType(GuestType newType)
{
    type = newType;
}

void Guest::print() const {
    std::cout << "Guest ID: " << id << "\n"
        << "Name: " << name.getString() << "\n"
        << "Phone: " << phone.getString() << "\n"
        << "Email: " << email.getString() << "\n"
        << "Type: ";
    switch (type) {
    case GuestType::REGULAR: std::cout << "Regular"; break;
    case GuestType::GOLD:    std::cout << "Gold"; break;
    case GuestType::PLATINUM:std::cout << "Platinum"; break;
    }
    std::cout << "\n";
}

