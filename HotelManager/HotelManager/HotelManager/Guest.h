#pragma once
#include "MyString.h"
#include "GuestType.h"

class Guest {
private:
    MyString name;
    MyString phone;
    MyString email;
    unsigned id;
    GuestType type;

public:
    Guest();
    Guest(const MyString& name, const MyString& phone, const MyString& email, unsigned id, GuestType type = GuestType::REGULAR);

    const MyString& getName() const;
    const MyString& getPhone() const;
    const MyString& getEmail() const;
    unsigned getId() const;
    GuestType getType() const;
    double getDiscountPercent() const;
    void setType(GuestType newType);


    void print() const;
};


