#include "Ship.h"
#include <iostream>

int main () {

    Ship Ship1;
    std::cout << "The ships name is " << Ship1.GetName() << " With length " << Ship1.GetLength() << std::endl;

    return 0;
}