#ifndef PLAYER_H
#define PLAYER_H

#include "User.h"

class Player: public User {

    public:
        Player();
        void Move(User* opponent);
        void DisplayBoard();
        void Quit();

};

#endif
