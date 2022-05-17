#include <iostream>
#include <string>
#include <stdlib.h>
#include "Computer.h"
#include <chrono>
#include <thread>

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
    std::cout << "Computer placed Flagship at (" << x << "," << y << ")" << std::endl;

    //placing Destroyer
    x = rand() % 5;
    y = 2;
    for(int i = x; i < x+Ships[1].GetLength();i ++){
                    Ships[1].WriteShipData(i-x+1,i,y); // change 1
                }
    std::cout << "Computer placed Destroyer at (" << x << "," << y << ")" << std::endl;

    //placing Carrier1
    x = rand() % 6;
    y = 3;
    for(int i = x; i < x+Ships[2].GetLength();i ++){
                    Ships[2].WriteShipData(i-x+1,i,y); // change 1
                }
    std::cout << "Computer placed Carrier1 at (" << x << "," << y << ")" << std::endl;

    //placing Carrier2
    x = rand() % 6;
    y = 4;
    for(int i = x; i < x+Ships[3].GetLength();i ++){
                    Ships[3].WriteShipData(i-x+1,i,y); // change 1
                }
    std::cout << "Computer placed Carrier2 at (" << x << "," << y << ")" << std::endl;

    //placing Submarine1
    x = rand() % 7;
    y = 5;
    for(int i = x; i < x+Ships[4].GetLength();i ++){
                    Ships[4].WriteShipData(i-x+1,i,y); // change 1
                }
    std::cout << "Computer placed Submarine1 at (" << x << "," << y << ")" << std::endl;

    //placing Submarine2
    x = rand() % 7;
    y = 6;
    for(int i = x; i < x+Ships[5].GetLength();i ++){
                    Ships[5].WriteShipData(i-x+1,i,y); // change 1
                }
    std::cout << "Computer placed Submarine2 at (" << x << "," << y << ")" << std::endl;

    //placing Scout Boat1
    x = rand() % 8;
    y = 7;
    for(int i = x; i < x+Ships[6].GetLength();i ++){
                    Ships[6].WriteShipData(i-x+1,i,y); // change 1
                }
    std::cout << "Computer placed Scout Boat1 at (" << x << "," << y << ")" << std::endl;

    //placing Scout Boat1
    x = rand() % 8;
    y = 8;
    for(int i = x; i < x+Ships[7].GetLength();i ++){
                    Ships[7].WriteShipData(i-x+1,i,y); // change 1
                }
    std::cout << "Computer placed Scout Boat2 at (" << x << "," << y << ")" << std::endl;

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<8;k++){
                for(int m = 0; m < Ships[k].GetLength(); m++) {
                    if(Ships[k].ReturnCoords(m+1) == i + j*10) {
                        ShipBoard[i][j] = k+1;
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
            for(int i=0;i<8;i++) {
                if ((*opponent).Ships[i].ShipHit(y,x)) {
                    std::cout << "Computer hit a ship at (" << x << "," << y << ")" << std::endl;
                    HitBoard[x][y] = 2;
                    i = 8;
                } else {
                    HitBoard[x][y] = 1;
                }
            }
            z = false;
        }
    }
    std::cout<<"Computer moved at (" << x << "," << y << ")"<< std::endl;
    //std::this_thread::sleep_for (std::chrono::milliseconds(1000));
}

void Computer::DisplayBoard(User* opponent){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            std::cout<< ShipBoard[i][j] << " ";
        }
        std::cout << "| ";
        for (int m = 0; m < 10; m++) {
            std::cout << HitBoard[i][m] << " ";
        }
        std::cout<<std::endl;
    }
}