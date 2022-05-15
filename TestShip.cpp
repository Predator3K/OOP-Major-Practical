#include "Ship.h"
#include <iostream>

int main () {

    Ship Ship1;
    std::cout << "The ships name is " << Ship1.GetName() << " With length " << Ship1.GetLength() << std::endl;
    Ship Ship2("Destroyer", 6);
    std::cout << "The ships name is " << Ship2.GetName() << " With length " << Ship2.GetLength() << std::endl;

    Ship* Ships = new Ship[3];

    Ship Ship3("Boat", 3);
    Ship Ship4("Cruiser", 4);
    Ship Ship5("Carrier", 5);
    Ships[0] = Ship3;
    Ships[1] = Ship4;
    Ships[2] = Ship5;

    for (int i = 0; i < 3; i++) {
        std::cout << "The ships name is " << Ships[i].GetName() << " With length " << Ships[i].GetLength() << std::endl;
    }

    Ship* Ships2 = new Ship;
    std::cout << "The ships name is " << Ships2->GetName() << " With length " << Ships2->GetLength() << std::endl;

    for (int i = 0; i < 3; i++) {
        if (Ships[i].IsSunk() == false) {
            std::cout << "Ship " << Ships[i].GetName() << " is not sunk" << std::endl;
        } else {
            std::cout << "Ship " << Ships[i].GetName() << " is sunk" << std::endl;
        }
    }

    if (Ships[0].IsSunk() == false) {
            std::cout << "Ship " << Ships[0].GetName() << " is not sunk" << std::endl;
        } else {
            std::cout << "Ship " << Ships[0].GetName() << " is sunk" << std::endl;
    }

    Ships[0].WriteShipData(1, 3, 4);
    Ships[0].WriteShipData(2, 3, 5);
    Ships[0].WriteShipData(3, 3, 6);

    Ships[0].ShipHit(3,4);
    Ships[0].ShipHit(3,5);
    Ships[0].ShipHit(3,6);

    if (Ships[0].IsSunk() == false) {
            std::cout << "Ship " << Ships[0].GetName() << " is not sunk" << std::endl;
        } else {
            std::cout << "Ship " << Ships[0].GetName() << " is sunk" << std::endl;
    }

    return 0;
}