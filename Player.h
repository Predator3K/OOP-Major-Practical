#ifndef PLAYER_H
#define PLAYER_H

#include "User.h"

class Player: public User {

    public:
    
        //Constructor
        Player();
        
        //Allows player to make a move
        void Move(User* opponent);
        
        //Allows player to display their board;
        void DisplayBoard(User* opponent);

};

#endif
