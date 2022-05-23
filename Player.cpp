#include <iostream>
#include <string>
#include "Player.h"

Player::Player(){
    int x = 0;
    int y =0;

    int counter = 0;

    while (counter<8){
        std::cout << "Please input the x-coordinate for "<<Ships[counter].GetName() <<std::endl;
        std::cin >> x;
        if(x>0 && x<10){

            while (true){
                std::cout<< "Please input the y-coordinate for "<<Ships[counter].GetName() <<std::endl;
                std::cin>> y;
                if(y>0 && y<10){
                    if(x + Ships[counter].GetLength() < 10){
                    for(int i = x; i < x+Ships[counter].GetLength();i ++){
                        Ships[counter].WriteShipData(i-x+1,i,y); 
                }
                counter++;
                break;
            }
                }else{
                std::cout<< "Invalid y-coordinate for "<<Ships[counter].GetName() <<std::endl;
                }
            }
        }else{
        std::cout<< "Invalid x-coordinate for "<<Ships[counter].GetName() <<std::endl;
        }
    }

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

void Player::Move(User* opponent){
    int x = 0;
    int y = 0;
    bool z = true;
    while(z){
        std::cout<< "Please input the x-coordinate (Or -1 to Quit)" <<std::endl;
        std::cin>> x;
        if(x == -1) {
            for(int i =0;i<8;i++){
            Ships[i].Sink();
            ((*opponent).GetShips())[i].Sink();
            }
            return;
        }
        std::cout<< "Please input the y-coordinate" <<std::endl;
        std::cin>> y;
        if(HitBoard[x][y] == 0){
            for(int i=0;i<8;i++) {
                if (((*opponent).GetShips())[i].ShipHit(y,x)) {
                    std::cout << "Player hit a ship at (" << x << "," << y << ")" << std::endl;
                    HitBoard[x][y] = 2;
                    i = 8;
                } else {
                    HitBoard[x][y] = 1;
                }
            }
            z = false;
        }else{
            std::cout<< "Please put in coordinates you have not hit" <<std::endl;
        }

    }
    return;
}

void Player::DisplayBoard(User* opponent){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            std::cout << ShipBoard[i][j] << " ";
        }
        std::cout << "| ";
        for (int m = 0; m < 10; m++) {
            std::cout << HitBoard[i][m] << " ";
        }
        std::cout << "| ";
        for (int m = 0; m < 10; m++) {
            std::cout << ((*opponent).GetHitBoard())[i][m] << " ";
        }
        std::cout<<std::endl;
    }
    return;
}
