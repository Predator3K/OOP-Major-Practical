#ifndef COMPUTER_H
#define COMPUTER_H

#include "User.h"

class Computer: public User {

    public:

        //Constructor
        Computer();

        //Allows computer to make a move
        void Move(User* opponent);

        //Allows computer to display their board (if necessary)
        void DisplayBoard(User* opponent);
};

#endif