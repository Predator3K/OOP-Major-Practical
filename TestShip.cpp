#include "Ship.h"
#include <iostream>

int main () {

    Ship Ship1;
    std::cout << "The ships name is " << Ship1.GetName() << " With length " << Ship1.GetLength() << std::endl;
    Ship Ship2("Destroyer", 1, 6);
    std::cout << "The ships name is " << Ship2.GetName() << " With length " << Ship2.GetLength() << std::endl;

    Ship* Ships = new Ship[3];

    Ship Ship3("Boat", 1, 3);
    Ship Ship4("Cruiser", 2, 4);
    Ship Ship5("Carrier", 3, 5);
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

    return 0;
}