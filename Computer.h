#ifndef COMPUTER_H
#define COMPUTER_H

#include "User.h"

class Computer: public User {

    public:
        Computer();
        void Move(User* opponent);
        void DisplayBoard();
};

#endif