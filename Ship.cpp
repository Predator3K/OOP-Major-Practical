#include "Ship.h"

//Constructs a default ship with 0 length, no name, a nullptr for the data and not sunk
Ship::Ship(): _ShipLength(0), _ShipName("Null"), _ShipData(nullptr), _IsSunk(false) {}

//Constructs a ship with all the info provided and creates an int array with the ship length, sets all entries to 1100, 1200, 1300 etc.
Ship::Ship(std::string name, int length): _ShipLength(length), _ShipName(name), _IsSunk(false) {

    if (_ShipLength != 0) {
            _ShipData = new int[length];

        for (int i = 0; i < _ShipLength; i++) {
            _ShipData[i] = 1000 + (i+1)*100;
        }
    } else {
        _ShipData = nullptr;
    }
}

//returns the ship name
std::string Ship::GetName() {
    return _ShipName;
}

//returns the ship length
int Ship::GetLength() {
    return _ShipLength;
}

//checks if a specific piece is hit or not
bool Ship::IsHit(int piece) {
    if(_ShipData[piece] == 1) {
        return false;
    } else {
        return true;
    }
}

//checks if the ship is sunk, and once it is, simply returns it being sunk (doesnt check every time)
bool Ship::IsSunk() {

    if (_IsSunk != true) {
        int Sum = 0;
        for (int i = 0; i < _ShipLength; i++) {
            Sum = Sum + _ShipData[i]/1000;
        }

        if(Sum == 0) {
            _IsSunk = true;
            return true;
        } else {
            return false;
        }
    }

    return _IsSunk;
}

//allows the coordinates of the ship to be written into the ship
void Ship::WriteShipData(int piece, int x, int y) {
    _ShipData[piece-1] = _ShipData[piece-1] + 10*x + y;
    return;
}

//hits the ship given the x and y coords
bool Ship::ShipHit(int x, int y) {
    for (int i = 0; i < _ShipLength; i++) {
        if (_ShipData[i]%100 == 10*x+y) { //checks the 3rd and 4th element of the shipdata and if it is equal to xy (in that order, not the product) sets that piece to 'hit'
            _ShipData[i] = _ShipData[i] - 1000;
            return true;
        }
    }

    return false;
}

void Ship::Sink() {
    _IsSunk = true;
    return;
}

int Ship::ReturnCoords(int piece) {
    return _ShipData[piece-1]%100;
}

//deconstructs the int array when done
Ship::~Ship() {
    delete[] _ShipData;
}