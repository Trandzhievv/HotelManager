#pragma once
#include "HotelSystem.h"

class DataManager {
public:
    static void saveToFile(HotelSystem& system, const char* filename);
    static void loadFromFile(HotelSystem& system, const char* filename);
};

