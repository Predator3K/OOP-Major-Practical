#ifndef SHIP_H
#define SHIP_H

#include <string>

class Ship {

    private:
        int _ShipLength;
        std::string _ShipName;
        int _ShipNumber;
        int* _ShipData;
        bool _IsSunk;

    public:
        //Default constructor
        Ship();

        //Constructor takes a string
        Ship(std::string name, int number, int length);

        //Returns the ship name
        std::string GetName();

        //Returns the ship length
        int GetLength();

        //Returns if that ship's piece is hit
        bool IsHit(int piece);

        //Returns if the ship is sunk or not (true or false)
        bool IsSunk();

        //Allows the game to write in the ships data
        void WriteShipData(int piece, int x, int y);

        //Deconstructor
        ~Ship();
};

#endif