#pragma once
#include "User.h"

class Accountant : public User {
public:
    Accountant() = default;
    Accountant(const MyString& username);
    bool can(const MyString& action) const override;
    MyString getRole() const override;
    User* clone() const override;
};

