#include "UserFactory.h"

User* UserFactory::createUser(const MyString& roleName) {
    if (roleName == "receptionist")
        return new Receptionist();
    else if (roleName == "manager")
        return new Manager();
    else if (roleName == "accountant")
        return new Accountant();

    return nullptr; 
}

User* UserFactory::createUser(const MyString& username, const MyString& roleName) {
    if (roleName == "receptionist")
        return new Receptionist(username);
    else if (roleName == "manager")
        return new Manager(username);
    else if (roleName == "accountant")
        return new Accountant(username);

    return nullptr;
}

