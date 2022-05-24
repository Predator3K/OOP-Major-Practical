#include <iostream>
#include <string>
#include <stdlib.h>
#include "Computer.h"
#include <time.h>

using namespace std::chrono_literals;

Computer::Computer(){

    std::cout << "Constructing computer..." << std::endl;

    int x = 0;
    int y = 0;
    int direction = 0;

    //Used for checking if the x, y, direction and overlap are valid
    bool xvalid = false;
    bool yvalid = false;
    bool DirectionValid = false;
    bool overlap = false;

    //Used for checking if a given direction is valid
    bool leftvalid = true;
    bool rightvalid = true;
    bool upvalid = true;
    bool downvalid = true;

    //Used to loop over all the boats
    int counter = 0;

    //Loops through all the boats
    while (counter < 5) {
        srand((int) time(0));
        //If the x input is a number, checks if it is between 0 and 9, if not it asks again
        if(xvalid == false) {
            x = rand() % 9;
            xvalid = true;
        }

        //If the y input is valid, checks if it is between 0 and 9, if not it asks again
        if(xvalid == true && yvalid == false) {
            y = rand() % 9;
            yvalid = true;
        }

        //If the x and y inputs are valid, checks if that current spot has a boat at it already, and if it does says it overlaps
        if(xvalid == true && yvalid == true) {
            if (ShipBoard[x][y] != 0) {
                xvalid = false;
                yvalid = false;
            }
        }

        //If the coordinates are valid and there is no current overlap, asks the user for which direction they'd like to place in. If this is invalid, it asks again
        if (xvalid == true && yvalid == true) {
            direction = rand() % 4 + 1;
        }

        //If the coordinates are valid and there is no current overlap, asks the user to pick a direction to place the boat in
        if(xvalid == true && yvalid == true) {

            //Places the boat in the right direction
            if (direction == 1) {

                //Checks if the boat will go outside the boat if placed to the right, if it does, says it will go out of bounds
                if(x + Ships[counter].GetLength() < 11) {

                    //Checks if the boat overlaps another boat currently placed on the board, if it does, it says so and asks for a new direction
                    for (int i = 0; i < Ships[counter].GetLength(); i++) {
                        if (ShipBoard[x+i][y] != 0) {
                            overlap = true;
                        }
                    }

                    //If there is no overlap, writes in the corresponding information into the ShipBoard and relevent Ship object and then resets, asking for the next boat
                    if (overlap == false) {

                        //Writes in the ship data
                        for(int i = x; i < x+Ships[counter].GetLength();i ++) {
                            Ships[counter].WriteShipData(i-x+1,i,y);
                        }

                        //Sets the checking flags to false for a new boat
                        xvalid = false;
                        yvalid = false;
                        DirectionValid = false;

                        //Puts the ship on the board
                        for(int i=0;i<10;i++){
                            for(int j=0;j<10;j++){
                                for(int m = 0; m < Ships[counter].GetLength(); m++) {
                                    if(Ships[counter].ReturnCoords(m+1) == i + j*10) {
                                        ShipBoard[j][i] = counter+1;
                                    }
                                }
                            }
                        }
                        counter++;
                    }   else {
                            //Says the boat is overlapping another ship
                            DirectionValid = false;
                            overlap = false;
                            rightvalid = false;
                    }
                } else {
                        //Says the boat will go outside of the board
                        DirectionValid = false;
                        rightvalid = false;
                }

            //Places the boat in the left direction, in the exact same manner as above but changed as required to put the boat to the left
            } else if (direction == 2) {
                if(x - Ships[counter].GetLength() > -2) {
                    for (int i = 0; i < Ships[counter].GetLength(); i++) {
                        if (ShipBoard[x-i][y] != 0) {
                            overlap = true;
                        }
                    }
                    if (overlap == false) {
                        for(int i = x; i < x + Ships[counter].GetLength(); i++) {
                            Ships[counter].WriteShipData(i-x+1,2*x-i,y);
                        }
                        xvalid = false;
                        yvalid = false;
                        overlap = false;
                        DirectionValid = false;
                        for(int i=0;i<10;i++){
                            for(int j=0;j<10;j++){
                                for(int m = 0; m < Ships[counter].GetLength(); m++) {
                                    if(Ships[counter].ReturnCoords(m+1) == i + j*10) {
                                        ShipBoard[j][i] = counter+1;
                                    }
                                }
                            }
                        }
                        counter++;
                    } else {
                        DirectionValid = false;
                        overlap = false;
                        leftvalid = false;
                    }
                }   else {
                            DirectionValid = false;
                            leftvalid = false;
                        }

            //Places the boat in the down direction, in the exact same manner as above but changed as required to put the boat to the down
            } else if (direction == 3) {
                if(y + Ships[counter].GetLength() < 11) {
                    for (int i = 0; i < Ships[counter].GetLength(); i++) {
                        if (ShipBoard[x][y+i] != 0) {
                            overlap = true;
                        }
                    }
                    if (overlap == false) {
                        for(int i = y; i < y + Ships[counter].GetLength(); i++) {
                            Ships[counter].WriteShipData(i-y+1,x,i);
                        }
                        xvalid = false;
                        yvalid = false;
                        overlap = false;
                        DirectionValid = false;
                        for(int i=0;i<10;i++){
                            for(int j=0;j<10;j++){
                                for(int m = 0; m < Ships[counter].GetLength(); m++) {
                                    if(Ships[counter].ReturnCoords(m+1) == i + j*10) {
                                        ShipBoard[j][i] = counter+1;
                                    }
                                }
                            }
                        }
                        counter++;
                    } else {
                        DirectionValid = false;
                        overlap = false;
                        downvalid = false;
                    }
                }   else {
                            DirectionValid = false;
                            downvalid = false;
                        }

            //Places the boat in the up direction, in the exact same manner as above but changed as required to put the boat to the up
            } else if (direction == 4) {
                if(y - Ships[counter].GetLength() > -2) {
                    for (int i = 0; i < Ships[counter].GetLength(); i++) {
                        if (ShipBoard[x][y-i] != 0) {
                            overlap = true;
                        }
                    }
                    if (overlap == false) {
                        for(int i = y; i < y + Ships[counter].GetLength(); i++) {
                            Ships[counter].WriteShipData(i-y+1,x,2*y-i);
                        }
                        xvalid = false;
                        yvalid = false;
                        overlap = false;
                        DirectionValid = false;
                        for(int i=0;i<10;i++){
                            for(int j=0;j<10;j++){
                                for(int m = 0; m < Ships[counter].GetLength(); m++) {
                                    if(Ships[counter].ReturnCoords(m+1) == i + j*10) {
                                        ShipBoard[j][i] = counter+1;
                                    }
                                }
                            }
                        }
                        counter++;
                } else {
                        DirectionValid = false;
                        overlap = false;
                        upvalid = false;
                    }
                }   else {
                            DirectionValid = false;
                            upvalid = false;
                        }
            }
        }
        //If there are no valid placement directions (ie the boat is stuck) it says the boat is stuck and resets asking once again
        if (rightvalid == false && leftvalid == false && upvalid == false && downvalid == false) {
            xvalid = false;
            yvalid = false;
            DirectionValid = false;
            overlap = false;
            leftvalid = true;
            rightvalid = true;
            upvalid = true;
            downvalid = true;
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
            if(ShipBoard[i][j] == 0)
                std::cout << "- ";
            else {
                std::cout << ShipBoard[i][j] << " ";
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