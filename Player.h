#ifndef PLAYER_H
#define PLAYER_H

#include "User.h"

class Player: public User {

    public:
        Player();
        void Move();
        void DisplayBoard();
        void Quit;

};

#endif