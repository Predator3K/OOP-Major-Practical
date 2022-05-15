#include "Ship.h"

Ship::Ship(): _ShipLength(0), _ShipName("Null"), _ShipNumber(0), _ShipData(nullptr), _IsSunk(false) {}

Ship::Ship(std::string name, int number, int length): _ShipLength(length), _ShipName(name), _ShipNumber(number), _IsSunk(false) {

    if (_ShipLength != 0) {
            _ShipData = new int[length];

        for (int i = 0; i < _ShipLength; i++) {
            _ShipData[i] = 1000 + (i+1)*100;
        }
    } else {
        _ShipData = nullptr;
    }
}

std::string Ship::GetName() {
    return _ShipName;
}

int Ship::GetLength() {
    return _ShipLength;
}

bool Ship::IsHit(int piece) {
    if(_ShipData[piece] == 1) {
        return false;
    } else {
        return true;
    }
}

bool Ship::IsSunk() {

    if (_IsSunk != true) {
        int Sum = 0;
        for (int i = 0; i < _ShipLength; i++) {
            Sum = Sum + _ShipData[i]%1000;
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

void Ship::WriteShipData(int piece, int x, int y) {
    _ShipData[piece] = _ShipData[piece] + 10*x + y;
}

Ship::~Ship() {
    delete[] _ShipData;
}


