#pragma once
#include "User.h"

class Manager : public User {
public:
    Manager() = default;
    Manager(const MyString& username);
    bool can(const MyString& action) const override;
    MyString getRole() const override;
    User* clone() const override;
};

