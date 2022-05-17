#include <iostream>
#include <string>
#include "Player.h"

Player::Player(){
    int x = 0;
    int y =0;
    int arrx = [0,0,0,0,0,0,0,0];
    std::cout<< "Please input the x-coordinate for Flagship" <<std::endl;
    std::cin>> x;
    std::cout<< "Please input the y-coordinate for Flagship" <<std::endl;
    std::cin>> y;
    if(x > 10 || x < 0 ){
        std::cout<< "Please input a valid x-coordinat" <<std::endl;
    }
    else{
        if(x + Ships[0].GetLength < 10){
            for(int i = x; i < x+Ships[0].GetLength;i ++){
                Ships[0].WriteShipData(1,i,y);

            }
        arrx[0] = x;
        }
    }
    //---------------------------------------------
    std::cout<< "Please input the x-coordinate for Destroyer" <<std::endl;
    std::cin>> x;
    std::cout<< "Please input the y-coordinate for Destroyer" <<std::endl;
    std::cin>> y;

    if(x > 10 || x < 0 ){
        std::cout<< "Please input a valid x-coordinat" <<std::endl;
    }
    else{
        
        if(x>arrx[0]+Ships[0].GetLength || x+Ships[1].GetLength < arrx[0]){
            if(x + Ships[1].GetLength < 10){
                for(int i = x; i < x+Ships[1].GetLength;i ++){
                    Ships[1].WriteShipData(1,i,y);
                }
            arrx[1] = x;
            arry[1] = y;
            }
        }
    }
    //---------------------------------------------------------
    std::cout<< "Please input the x-coordinate for Carrier" <<std::endl;
    std::cin>> x;
    std::cout<< "Please input the y-coordinate for Carrier" <<std::endl;
    std::cin>> y;

    if(x > 10 || x < 0 ){
        std::cout<< "Please input a valid x-coordinat" <<std::endl;
    }
    else{
        
        if(x>arrx[1]+Ships[1].GetLength || x+Ships[2].GetLength < arrx[1]){
            if(x + Ships[2].GetLength < 10){
                for(int i = x; i < x+Ships[2].GetLength;i ++){
                    Ships[2].WriteShipData(1,i,y); // change 1 
                }
            arrx[2] = x;
            arry[2] = y;
            }
        }
    }
    //-------------------------------------------
     std::cout<< "Please input the x-coordinate for Carrier" <<std::endl;
    std::cin>> x;
    std::cout<< "Please input the y-coordinate for Carrier" <<std::endl;
    std::cin>> y;

    if(x > 10 || x < 0 ){
        std::cout<< "Please input a valid x-coordinat" <<std::endl;
    }
    else{
        
        if(x>arrx[2]+Ships[2].GetLength || x+Ships[3].GetLength < arrx[2]){
            if(x + Ships[3].GetLength < 10){
                for(int i = x; i < x+Ships[3].GetLength;i ++){
                    Ships[3].WriteShipData(1,i,y); // change 1 
                }
            arrx[3] = x;
            arry[3] = y;
            }
        }
    }
    //-----------------------------------
    std::cout<< "Please input the x-coordinate for Submarine" <<std::endl;
    std::cin>> x;
    std::cout<< "Please input the y-coordinate for Submarine" <<std::endl;
    std::cin>> y;

    if(x > 10 || x < 0 ){
        std::cout<< "Please input a valid x-coordinat" <<std::endl;
    }
    else{
        
        if(x>arrx[3]+Ships[3].GetLength || x+Ships[4].GetLength < arrx[3]){
            if(x + Ships[4].GetLength < 10){
                for(int i = x; i < x+Ships[4].GetLength;i ++){
                    Ships[4].WriteShipData(1,i,y); // change 1 
                }
            arrx[4] = x;
            arry[4] = y;
            }
        }
    }
    //----------------------
    std::cout<< "Please input the x-coordinate for Submarine" <<std::endl;
    std::cin>> x;
    std::cout<< "Please input the y-coordinate for Submarine" <<std::endl;
    std::cin>> y;

    if(x > 10 || x < 0 ){
        std::cout<< "Please input a valid x-coordinat" <<std::endl;
    }
    else{
        
        if(x>arrx[4]+Ships[4].GetLength || x+Ships[5].GetLength < arrx[4]){
            if(x + Ships[5].GetLength < 10){
                for(int i = x; i < x+Ships[5].GetLength;i ++){
                    Ships[5].WriteShipData(1,i,y); // change 1 
                }
            arrx[5] = x;
            arry[5] = y;
            }
        }
    }
    //-----------------------
    std::cout<< "Please input the x-coordinate for Scout Boat" <<std::endl;
    std::cin>> x;
    std::cout<< "Please input the y-coordinate for Scout Boat" <<std::endl;
    std::cin>> y;

    if(x > 10 || x < 0 ){
        std::cout<< "Please input a valid x-coordinat" <<std::endl;
    }
    else{
        
        if(x>arrx[5]+Ships[5].GetLength || x+Ships[5].GetLength < arrx[5]){
            if(x + Ships[5].GetLength < 10){
                for(int i = x; i < x+Ships[6].GetLength;i ++){
                    Ships[6].WriteShipData(1,i,y); // change 1 
                }
            arrx[6] = x;
            arry[6] = y;
            }
        }
    }
    //----------------
    std::cout<< "Please input the x-coordinate for Scout Boat" <<std::endl;
    std::cin>> x;
    std::cout<< "Please input the y-coordinate for Scout Boat" <<std::endl;
    std::cin>> y;

    if(x > 10 || x < 0 ){
        std::cout<< "Please input a valid x-coordinat" <<std::endl;
    }
    else{
        
        if(x>arrx[6]+Ships[6].GetLength || x+Ships[6].GetLength < arrx[6]){
            if(x + Ships[6].GetLength < 10){
                for(int i = x; i < x+Ships[7].GetLength;i ++){
                    Ships[7].WriteShipData(1,i,y); // change 1 
                }
            arrx[7] = x;
            arry[7] = y;
            }
        }
    }
    //---------------------------------------------
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<8;k++){
                if(i== arry && j==arrx){
                    ShipBoard[i][j]=2;
                }else{
                    ShipBoard[i][j]=0;
                }

            }
        }
    }
}

void Player::Move(User* opponent){
    int x = 0;
    int y =0;
    bool z = true;
    while(z = true){
        std::cout<< "Please input the x-coordinate" <<std::endl;
        std::cin>> x;
        std::cout<< "Please input the y-coordinate" <<std::endl;
        std::cin>> y;
        if(HitBoard[x][y] == 0){
            for(int i=0;i<8;i++){
                (*opponent).Ships[i].ShipHit(x,y);
            }
            z = false;
        }else{
            std::cout<< "Please put in coordinates you have not hit" <<std::endl;
        }
    }
}

void Player::DisplayBoard(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            std::cout<<ShipBoard[i][j];
        }
        std::cout<<std::endl;
    }
}

void Player::Quit(){
    for(int i =0;i<8;i++){
        Ships[i].Sink;
    }
}
