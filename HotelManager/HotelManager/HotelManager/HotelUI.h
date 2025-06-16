#pragma once
#include "HotelSystem.h"
#include "User.h"
#include "DataManager.h"

class HotelUI {
public:
    static void run(HotelSystem& system, User* user);
};

