#ifndef USER_H
#define USER_H

#include "Ship.h"

class User {

    protected:

        //Board for the ships for the user
        int ShipBoard[10][10];

        //Pointer for the ships
        Ship* Ships;

        //Board for the shots the player has taken
        int** HitBoard;

    public:

        //Constructor
        User();

        Ship* GetShips();

        int** GetHitBoard();

        //Checks if the user won against the other user
        bool WinCondition(User* opponent);

        //pure virtual function for a user to make a move
        virtual void Move(User* opponent) = 0;

        virtual void DisplayBoard(User* opponent) = 0;

        //Deconstructor
        ~User();

};

#endif