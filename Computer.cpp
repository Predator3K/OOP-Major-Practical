#include <iostream>
#include <string>
#include <stdlib.h>
#include "Computer.h"

using namespace std::chrono_literals;

Computer::Computer(){ //Computer Ship placement
    int x = 0;
    int y = 0;

    //placing Flagship
    x = rand() % 4;
    y = 1;
    for(int i = x; i < x+Ships[0].GetLength();i ++){
                    Ships[0].WriteShipData(i-x+1,i,y); // change 1
                }

    //placing Destroyer
    x = rand() % 5;
    y = 2;
    for(int i = x; i < x+Ships[1].GetLength();i ++){
                    Ships[1].WriteShipData(i-x+1,i,y); // change 1
                }

    //placing Carrier1
    x = rand() % 6;
    y = 3;
    for(int i = x; i < x+Ships[2].GetLength();i ++){
                    Ships[2].WriteShipData(i-x+1,i,y); // change 1
                }

    //placing Submarine1
    x = rand() % 7;
    y = 5;
    for(int i = x; i < x+Ships[3].GetLength();i ++){
                    Ships[3].WriteShipData(i-x+1,i,y); // change 1
                }

    //placing Scout Boat1
    x = rand() % 8;
    y = 7;
    for(int i = x; i < x+Ships[4].GetLength();i ++){
                    Ships[4].WriteShipData(i-x+1,i,y); // change 1
                }

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<5;k++){
                for(int m = 0; m < Ships[k].GetLength(); m++) {
                    if(Ships[k].ReturnCoords(m+1) == i + j*10) {
                        ShipBoard[j][i] = k+1;
                    }
                }
            }
        }
    }
}

void Computer::Move(User* opponent){ //Computer moves, set on easy right now, compltetly random moves
    int x = 0;
    int y = 0;
    bool z = true;
    while(z) {
        x = rand() % 10;
        y = rand() % 10;
        if (HitBoard[x][y] == 0) {
            for(int i=0;i<5;i++) {
                if (((*opponent).GetShips())[i].ShipHit(y,x)) {
                    std::cout << "Computer has hit a ship at (" << x << "," << y << ")" << std::endl;
                    HitBoard[x][y] = 2;
                    break;
                } else {
                    HitBoard[x][y] = 1;
                }
            }
            z = false;
        }
    }
    std::cout<<"Computer moved at (" << x << "," << y << ")"<< std::endl;
}

void Computer::DisplayBoard(User* opponent){
     std::cout << std::endl;
    std::cout << "Where computer has hit  Computer Ship Board   Where computer enemy has hit" << std::endl;
    std::cout << "  0 1 2 3 4 5 6 7 8 9" << std::endl;
    for(int i=0;i<10;i++){
        std::cout << i << " ";
        for (int m = 0; m < 10; m++) {
            if(HitBoard[m][i] == 0)
                std::cout << "- ";
            else if(HitBoard[m][i] == 1)
                std::cout << "O ";
            else {
                std::cout << "X ";
            }
        }
        std::cout << "| ";
        for(int j=0;j<10;j++){
            if(ShipBoard[j][i] == 0)
                std::cout << "- ";
            else {
                std::cout << ShipBoard[j][i] << " ";
            }
        }
        std::cout << "| ";
        for (int m = 0; m < 10; m++) {
            if(((*opponent).GetHitBoard())[m][i] == 0)
                std::cout << "- ";
            else if(((*opponent).GetHitBoard())[m][i] == 1)
                std::cout << "O ";
            else {
                std::cout << "X ";
            }
        }
        std::cout<<std::endl;
    }
    std::cout << std::endl;
    return;
}