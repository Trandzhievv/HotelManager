#include "User.h"

User::User(const MyString& username) : username(username) {}

MyString User::getUsername() const {
    return username;
}