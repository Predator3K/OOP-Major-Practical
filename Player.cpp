#include <iostream>
#include <string>
#include<limits>
#include "Player.h"

using namespace std;

Player::Player(){

    std::string x1 = "";
    std::string y1 = "";

    int x = 0;
    int y = 0;

    bool xvalid = true;
    bool yvalid = true;

    int counter = 0;

    while (counter < 5) {
        std::cout << "Please input the x-coordinate for " << Ships[counter].GetName() << " between 0 and 9" << std::endl;
        std::cin >> x1;
        for(int i = 0; i < x1.length(); i++) {
            if(isdigit(x1[i]) == false) {
                xvalid = false;
                std::cout << "Invalid input: please input a number between 0 to 9" << std::endl;
                break;
            }
        }
        if(xvalid == true) {
            x = std::stoi(x1);
            if (x < 0 || x > 9) {
                xvalid = false;
                std::cout << "Invalid input: please input a number between 0 to 9" << std::endl;
            }
        }
        if(xvalid == true) {
            std::cout << "Please input the y-coordinate for "<<Ships[counter].GetName() << " between 0 and 9" << std::endl;
            std::cin >> y1;
            for(int i = 0; i < y1.length(); i++) {
                if(isdigit(y1[i]) == false) {
                    yvalid = false;
                    std::cout << "Invalid input: please input a number between 0 to 9" << std::endl;
                    break;
                }
            }
        }
        if(xvalid == true && yvalid == true) {
            y = std::stoi(y1);
            if (y < 0 || y > 9) {
                yvalid = false;
                std::cout << "Invalid input: please input a number between 0 to 9" << std::endl;
            }
        }
        if(xvalid == true && yvalid == true) {
            if(x + Ships[counter].GetLength() < 11) {
                for(int i = x; i < x+Ships[counter].GetLength();i ++) {
                    Ships[counter].WriteShipData(i-x+1,i,y);
                }
                for(int i=0;i<10;i++){
                    for(int j=0;j<10;j++){
                        for(int k=0;k<counter+1;k++){
                            for(int m = 0; m < Ships[k].GetLength(); m++) {
                                if(Ships[k].ReturnCoords(m+1) == i + j*10) {
                                    ShipBoard[j][i] = k+1;
                                }
                            }
                        }
                    }
                }
                counter++;
                if (counter < 5) {
                    std::cout << "  0 1 2 3 4 5 6 7 8 9" << std::endl;
                    for(int i = 0; i < 10; i++) {
                        std::cout << i << " ";
                        for(int j = 0; j < 10; j++){
                            if(ShipBoard[j][i] == 0)
                                std::cout << "- ";
                            else {
                            std::cout << ShipBoard[j][i] << " ";
                            }
                        }
                        std::cout << std::endl;
                    }
                }
            } else {
                std::cout << Ships[counter].GetName() << " goes outside the range of the board, please try again" <<std::endl;
            }
        }
        xvalid = true;
        yvalid = true;
    }



}

void Player::Move(User* opponent){

    std::string x1 = "";
    std::string y1 = "";

    int x = 0;
    int y = 0;

    bool xvalid = true;
    bool yvalid = true;

    bool z = true;
    while (z) {
        std::cout<< "Please input the x-coordinate between 0 to 9 to hit (Or 10 to Quit)" <<std::endl;
        std::cin>> x1;
        for(int i = 0; i < x1.length(); i++) {
            if(isdigit(x1[i]) == false) {
                xvalid = false;
                std::cout << "Invalid input: please input a number between 0 to 9 or 10 to quit" << std::endl;
                break;
            }
        }
        if(xvalid == true) {
            x = std::stoi(x1);
            if (x < 0 || x > 10) {
                xvalid = false;
                std::cout << "Invalid input: please input a number between 0 to 9 or 10 to quit" << std::endl;
            }
        }
        if(xvalid == true && x == 10) {
            for(int i =0;i<5;i++){
            Ships[i].Sink();
            ((*opponent).GetShips())[i].Sink();
            }
            return;
        }
        if(xvalid == true) {
            std::cout<< "Please input the y-coordinate between 0 to 9 to hit" <<std::endl;
            std::cin >> y1;
            for(int i = 0; i < y1.length(); i++) {
                if(isdigit(y1[i]) == false) {
                    yvalid = false;
                    std::cout << "Invalid input: please input a number between 0 to 9" << std::endl;
                    break;
                }
            }
        }
        if(xvalid == true && yvalid == true) {
            y = std::stoi(y1);
            if (y < 0 || y > 9) {
                yvalid = false;
                std::cout << "Invalid input: please input a number between 0 to 9" << std::endl;
            }
        }
        if(xvalid == true && yvalid == true) {
            if(HitBoard[x][y] == 0){
                for(int i=0;i<5;i++) {
                    if (((*opponent).GetShips())[i].ShipHit(x,y)) {
                        std::cout << "Player has hit a ship at (" << x << "," << y << ")" << std::endl;
                        HitBoard[x][y] = 2;
                        i = 8;
                    } else {
                        HitBoard[x][y] = 1;
                    }
                }
                z = false;
            } else {
                std::cout<< "Please put in coordinates you have not hit" <<std::endl;
            }
        }
        xvalid = true;
        yvalid = true;
    }
    return;
}

void Player::DisplayBoard(User* opponent){
    std::cout << std::endl;
    std::cout << "  Where you have hit     Your Ship Board      Where your enemy has hit" << std::endl;
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
