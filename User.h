#ifndef USER_H
#define USER_H

#include "Ship.h"
#include <chrono>
#include <ctime>

class User {

    protected:

        //Board for the ships for the user
        int ShipBoard[10][10];

        //Pointer for the ships
        Ship* Ships;

        //Board for the shots the player has taken
        int** HitBoard;

        std::chrono::time_point<std::chrono::system_clock> start;

    public:

        //Constructor
        User();

        //Returns the ships array
        Ship* GetShips();

        //Returns the hit board array
        int** GetHitBoard();

        //Checks if the user won against the other user
        bool WinCondition(User* opponent);

        //pure virtual function for a user to make a move
        virtual void Move(User* opponent) = 0;

        //Allows computer/player to display their board
        virtual void DisplayBoard(User* opponent) = 0;

        int GameTimer();

        //Virtual Deconstructor
        virtual ~User();

};

#endif
