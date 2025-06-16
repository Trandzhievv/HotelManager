#pragma once
#include "MyString.h"

class User {

protected:
    MyString username;

public:
    User() = default;
    User(const MyString& username);

    virtual bool can(const MyString& action) const = 0;
    virtual MyString getRole() const = 0;
    virtual User* clone() const = 0;
    virtual ~User() = default;

    MyString getUsername() const;
};

