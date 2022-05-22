#include <iostream>
#include <string>
#include "Player.h"

Player::Player(){
    int x = 0;
    int y =0;
    std::cout<< "Please input the x-coordinate for Flagship" <<std::endl;
    std::cin>> x;
    std::cout<< "Please input the y-coordinate for Flagship" <<std::endl;
    std::cin>> y;
    if(x > 10 || x < 0 ){
        std::cout<< "Please input a valid x-coordinate" <<std::endl;
    }
    else{
        if(x + Ships[0].GetLength() < 10){
            for(int i = x; i < x+Ships[0].GetLength();i ++){
                Ships[0].WriteShipData(i-x+1,i,y);
            }
        }
    }
    //---------------------------------------------
    std::cout<< "Please input the x-coordinate for Destroyer" <<std::endl;
    std::cin>> x;
    std::cout<< "Please input the y-coordinate for Destroyer" <<std::endl;
    std::cin>> y;

    if(x > 10 || x < 0 ){
        std::cout<< "Please input a valid x-coordinate" <<std::endl;
    }
    else{

        if(x + Ships[1].GetLength() < 10){
            for(int i = x; i < x+Ships[1].GetLength();i ++){
            Ships[1].WriteShipData(i-x+1,i,y);
            }
        }
    }
    //---------------------------------------------
    std::cout<< "Please input the x-coordinate for Carrier 1" <<std::endl;
    std::cin>> x;
    std::cout<< "Please input the y-coordinate for Carrier 1" <<std::endl;
    std::cin>> y;

    if(x > 10 || x < 0 ){
        std::cout<< "Please input a valid x-coordinate" <<std::endl;
    }
    else {
        if(x + Ships[2].GetLength() < 10){
            for(int i = x; i < x+Ships[2].GetLength();i ++){
                Ships[2].WriteShipData(i-x+1,i,y); // change 1
            }
        }
    }
    //---------------------------------------------
    std::cout<< "Please input the x-coordinate for Carrier 2" <<std::endl;
    std::cin>> x;
    std::cout<< "Please input the y-coordinate for Carrier 2" <<std::endl;
    std::cin>> y;

    if(x > 10 || x < 0 ){
        std::cout<< "Please input a valid x-coordinate" <<std::endl;
    }
    else{
        if(x + Ships[3].GetLength() < 10){
            for(int i = x; i < x+Ships[3].GetLength();i ++){
                Ships[3].WriteShipData(i-x+1,i,y); // change 1
            }
        }
    }
    //---------------------------------------------
    std::cout<< "Please input the x-coordinate for Submarine 1" <<std::endl;
    std::cin>> x;
    std::cout<< "Please input the y-coordinate for Submarine 1" <<std::endl;
    std::cin>> y;

    if(x > 10 || x < 0 ){
        std::cout<< "Please input a valid x-coordinate" <<std::endl;
    }
    else{
        if(x + Ships[4].GetLength() < 10){
            for(int i = x; i < x+Ships[4].GetLength();i ++){
                Ships[4].WriteShipData(i-x+1,i,y); // change 1
            }
        }
    }
    //---------------------------------------------
    std::cout<< "Please input the x-coordinate for Submarine 2" <<std::endl;
    std::cin>> x;
    std::cout<< "Please input the y-coordinate for Submarine 2" <<std::endl;
    std::cin>> y;

    if(x > 10 || x < 0 ){
        std::cout<< "Please input a valid x-coordinate" <<std::endl;
    }
    else{
        if(x + Ships[5].GetLength() < 10){
            for(int i = x; i < x+Ships[5].GetLength();i ++){
                Ships[5].WriteShipData(i-x+1,i,y); // change 1
            }
        }
    }
    //---------------------------------------------
    std::cout<< "Please input the x-coordinate for Scout Boat 1" <<std::endl;
    std::cin>> x;
    std::cout<< "Please input the y-coordinate for Scout Boat 1" <<std::endl;
    std::cin>> y;

    if(x > 10 || x < 0 ){
        std::cout<< "Please input a valid x-coordinate" <<std::endl;
    }
    else{
        if(x + Ships[5].GetLength() < 10){
            for(int i = x; i < x+Ships[6].GetLength();i ++){
                Ships[6].WriteShipData(i-x+1,i,y); // change 1
            }
        }
    }
    //---------------------------------------------
    std::cout<< "Please input the x-coordinate for Scout Boat 2" <<std::endl;
    std::cin>> x;
    std::cout<< "Please input the y-coordinate for Scout Boat 2" <<std::endl;
    std::cin>> y;

    if(x > 10 || x < 0 ){
        std::cout<< "Please input a valid x-coordinate" <<std::endl;
    }
    else{
        if(x + Ships[6].GetLength() < 10){
            for(int i = x; i < x+Ships[7].GetLength();i ++){
                Ships[7].WriteShipData(i-x+1,i,y); // change 1
            }
        }
    }
    //---------------------------------------------
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