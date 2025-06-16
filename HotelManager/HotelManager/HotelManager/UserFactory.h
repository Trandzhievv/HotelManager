#pragma once
#include "User.h"
#include "Receptionist.h"
#include "Manager.h"
#include "Accountant.h"

class UserFactory {
public:
    static User* createUser(const MyString& roleName);
    static User* createUser(const MyString& username, const MyString& roleName);
};


