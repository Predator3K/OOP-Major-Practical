#ifndef USER_H
#define USER_H

#include "Ship.h"

class User {

    public:

        //Board for the ships for the user
        int ShipBoard[10][10];

        //Board for the shots the player has taken
        int HitBoard[10][10];

        //Pointer for the ships
        Ship* Ships;

        //Constructor
        User();

        //Checks if the user won against the other user
        bool WinCondition(User* opponent);

        //pure virtual function for a user to make a move
        virtual void Move(User* opponent) = 0;

        virtual void DisplayBoard() = 0;

        //Deconstructor
        ~User();

};

#endif