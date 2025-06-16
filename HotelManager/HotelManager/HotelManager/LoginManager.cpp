#include "LoginManager.h"
#include "UserFactory.h"
#include <iostream>

User* LoginManager::login() {
    
    MyVector<User*> users;
    users.pushBack(UserFactory::createUser("Ivan", "receptionist"));
    users.pushBack(UserFactory::createUser("Maria", "manager"));
    users.pushBack(UserFactory::createUser("Georgi", "accountant"));

    MyString input;
    std::cout << "Enter your username: ";
    char buffer[64];
    std::cin >> buffer;
    input = MyString(buffer);


    for (size_t i = 0; i < users.getSize(); ++i) {
        if (users[i]->getUsername() == input) {
            std::cout << "Logged in as: " << users[i]->getRole().getString() << "\n";
            return users[i];
        }
    }

    std::cout << "User not found.\n";
    return nullptr;
}
