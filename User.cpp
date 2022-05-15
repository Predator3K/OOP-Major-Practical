#include "User.h"
#include <cstring>

User::User() {
    memset(HitBoard, 0, sizeof(HitBoard));
    memset(ShipBoard, 0, sizeof(ShipBoard));

    Ships = new Ship[8];

    new(&Ships[0]) Ship("Flagship", 6);
    new(&Ships[1]) Ship("Destroyer", 5);
    new(&Ships[2]) Ship("Carrier", 4);
    new(&Ships[3]) Ship("Carrier", 4);
    new(&Ships[4]) Ship("Submarine", 3);
    new(&Ships[5]) Ship("Submarine", 3);
    new(&Ships[6]) Ship("Scout Boat", 2);
    new(&Ships[7]) Ship("Scout Boat", 2);
}

bool User::WinCondition(User* opponent) {
    int ShipsSunk = 0;
    for (int i = 0; i < 8; i++) {
            if ((*opponent).Ships[i].IsSunk() == true) {
                ShipsSunk++;
        }
    }

    if (ShipsSunk == 8) {
        return true;
    }

    return false;
}

User::~User() {
    delete[] Ships;
}