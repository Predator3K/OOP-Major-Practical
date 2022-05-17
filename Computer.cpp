#include <iostream>
#include <string>
#include <stdlib.h>
#include "Computer.h"

Computer::Computer(){ //Computer Ship placement
    int x = 0;
    int y = 0;
    int arrx = [0,0,0,0,0,0,0,0];
    int arry = [0,0,0,0,0,0,0,0];

    //placing Flagship
    x = rand() % 4;
    y = rand() % 9;
    Ships[0].WriteShipData(0,x,y);
    arrx[0] = x;
    arry[0] = y;
    std::cout << "Computer placed Flagship at (" << x << ")(" << y << ")"<<endl;

    //placing Destroyer
    x = rand() % 5;
    y = rand() % 9;
    Ships[1].WriteShipData(1,x,y);
    arrx[1] = x;
    arry[1] = y;
    std::cout << "Computer placed Destroyer at (" << x << ")(" << y << ")"<<endl;

    //placing Carrier1
    x = rand() % 6;
    y = rand() % 9;
    Ships[2].WriteShipData(2,x,y);
    arrx[2] = x;
    arry[2] = y;
    std::cout << "Computer placed Carrier1 at (" << x << ")(" << y << ")"<<endl;

    //placing Carrier2
    x = rand() % 6;
    y = rand() % 9;
    Ships[3].WriteShipData(3,x,y);
    arrx[3] = x;
    arry[3] = y;
    std::cout << "Computer placed Carrier2 at (" << x << ")(" << y << ")"<<endl;

    //placing Submarine1
    x = rand() % 7;
    y = rand() % 9;
    Ships[4].WriteShipData(4,x,y);
    arrx[4] = x;
    arry[4] = y;
    std::cout << "Computer placed Submarine1 at (" << x << ")(" << y << ")"<<endl;

    //placing Submarine2
    x = rand() % 7;
    y = rand() % 9;
    Ships[5].WriteShipData(5,x,y);
    arrx[5] = x;
    arry[5] = y;
    std::cout << "Computer placed Submarine2 at (" << x << ")(" << y << ")"<<endl;

    //placing Scout Boat1
    x = rand() % 8;
    y = rand() % 9;
    Ships[6].WriteShipData(6,x,y);
    arrx[6] = x;
    arry[6] = y;
    std::cout << "Computer placed Scout Boat1 at (" << x << ")(" << y << ")"<<endl;

    //placing Scout Boat1
    x = rand() % 8;
    y = rand() % 9;
    Ships[7].WriteShipData(7,x,y);
    arrx[7] = x;
    arry[7] = y;
    std::cout << "Computer placed Scout Boat2 at (" << x << ")(" << y << ")"<<endl;
}

void Player::Move(User* opponent){ //Computer moves, set on easy right now, compltetly random moves
    int x = 0;
    int y =0;
    bool z = true;
    while(z = true){
        x = rand() % 9;
        y = rand() % 9;

        if(HitBoard[x][y] == 0){
            for(int i=0;i<8;i++){
                (*opponent).Ships[i].ShipHit(x,y);
            }
            z = false;
        }
    }
    std::cout<<"Computer moved at (" << x << ")(" << y << ")"<<endl;
}