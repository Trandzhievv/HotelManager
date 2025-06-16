#include "LoginManager.h"
#include "HotelSystem.h"
#include "HotelUI.h"

int main() {
    HotelSystem system;
    User* user = LoginManager::login();

    if (user) 
        HotelUI::run(system, user);
    

    return 0;
}
