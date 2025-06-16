#pragma once
#include "User.h"

class Receptionist : public User {
public:
    Receptionist() = default;
    Receptionist(const MyString& username);
    bool can(const MyString& action) const override;
    MyString getRole() const override;
    User* clone() const override;
};

