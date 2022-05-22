#ifndef SHIP_H
#define SHIP_H

#include <string>

class Ship {

    private:

        int _ShipLength;
        std::string _ShipName;
        int* _ShipData;
        bool _IsSunk;

    public:

        //Default constructor
        Ship();

        //Constructor takes a string, boat number and length
        Ship(std::string name, int length);

        //Returns the ship name
        std::string GetName();

        //Returns the ship length
        int GetLength();

        //Returns if the ship is sunk or not (true or false)
        bool IsSunk();

        //Allows the game to write in the ships data
        void WriteShipData(int piece, int x, int y);

        //Allows a ship piece to get hit given coordinates
        bool ShipHit(int x, int y);

        //sinks the ship
        void Sink();

        //Returns the coordinates of a piece
        int ReturnCoords(int piece);

        //Deconstructor
        ~Ship();
};

#endif