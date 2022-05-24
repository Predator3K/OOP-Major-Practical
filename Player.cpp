#include <iostream>
#include <string>
#include<limits>
#include "Player.h"

using namespace std;

Player::Player(){

    //Holds the users input x, y and direction
    std::string x1 = "";
    std::string y1 = "";
    std::string direction = "";

    //Holds the users input x and y when they are integers
    int x = 0;
    int y = 0;

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

        //Takes in the users x coordinate and checks if it is an integer, if not it asks again
        if (xvalid == false) {
            std::cout << "Please input the x-coordinate for " << Ships[counter].GetName() << " between 0 and 9" << std::endl;
            std::cin >> x1;
            for(int i = 0; i < x1.length(); i++) {
                if(isdigit(x1[i]) == false) {
                    std::cout << "Invalid input: please input a number between 0 to 9" << std::endl;
                    break;
                } else {
                    xvalid = true;
                }
            }
        }

        //If the x input is a number, checks if it is between 0 and 9, if not it asks again
        if(xvalid == true) {
            x = std::stoi(x1);
            if (x < 0 || x > 9) {
                xvalid = false;
                std::cout << "Invalid input: please input a number between 0 to 9" << std::endl;
            }
        }

        //If the x input is valid, asks for the y input, and if it is not an integer asks again
        if(xvalid == true && yvalid == false) {
            std::cout << "Please input the y-coordinate for "<<Ships[counter].GetName() << " between 0 and 9" << std::endl;
            std::cin >> y1;
            for(int i = 0; i < y1.length(); i++) {
                if(isdigit(y1[i]) == false) {
                    std::cout << "Invalid input: please input a number between 0 to 9" << std::endl;
                    break;
                } else {
                    yvalid = true;
                }
            }
        }

        //If the y input is valid, checks if it is between 0 and 9, if not it asks again
        if(xvalid == true && yvalid == true) {
            y = std::stoi(y1);
            if (y < 0 || y > 9) {
                yvalid = false;
                std::cout << "Invalid input: please input a number between 0 to 9" << std::endl;
            }
        }

        //If the x and y inputs are valid, checks if that current spot has a boat at it already, and if it does says it overlaps
        if(xvalid == true && yvalid == true) {
            if (ShipBoard[x][y] != 0) {
                std::cout << Ships[counter].GetName() << " overlaps another ship, please try again" <<std::endl;
                xvalid = false;
                yvalid = false;
            }
        }

        //If the coordinates are valid and there is no current overlap, asks the user for which direction they'd like to place in. If this is invalid, it asks again
        if (xvalid == true && yvalid == true) {
            std::cout << "Please input a direction you would like the ship to go: Up (u), Down (d), Left (l) or Right (r)" << std::endl;
            while (DirectionValid == false) {
                    std::cin >> direction;
                    if (direction == "u" || direction == "d" || direction == "r" || direction == "l") {
                        DirectionValid = true;
                    } else {
                        std::cout << "Invalid direction please try again" << std::endl;
                    }
            }
        }

        //If the coordinates are valid and there is no current overlap, asks the user to pick a direction to place the boat in
        if(xvalid == true && yvalid == true) {

            //Places the boat in the right direction
            if (direction == "r") {

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

                        //Displays the board and it current boats
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
                    }   else {
                            //Says the boat is overlapping another ship
                            std::cout << Ships[counter].GetName() << " overlaps another ship, please try again" <<std::endl;
                            DirectionValid = false;
                            overlap = false;
                            rightvalid = false;
                    }
                } else {
                        //Says the boat will go outside of the board
                        std::cout << Ships[counter].GetName() << " goes outside the range of the board, please try again" <<std::endl;
                        DirectionValid = false;
                        rightvalid = false;
                }

            //Places the boat in the left direction, in the exact same manner as above but changed as required to put the boat to the left
            } else if (direction == "l") {
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
                        std::cout << Ships[counter].GetName() << " overlaps another ship, please try again" <<std::endl;
                        DirectionValid = false;
                        overlap = false;
                        leftvalid = false;
                    }
                }   else {
                            std::cout << Ships[counter].GetName() << " goes outside the range of the board, please try again" <<std::endl;
                            DirectionValid = false;
                            leftvalid = false;
                        }

            //Places the boat in the down direction, in the exact same manner as above but changed as required to put the boat to the down
            } else if (direction == "d") {
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
                        std::cout << Ships[counter].GetName() << " overlaps another ship, please try again" <<std::endl;
                        DirectionValid = false;
                        overlap = false;
                        downvalid = false;
                    }
                }   else {
                            std::cout << Ships[counter].GetName() << " goes outside the range of the board, please try again" <<std::endl;
                            DirectionValid = false;
                            downvalid = false;
                        }

            //Places the boat in the up direction, in the exact same manner as above but changed as required to put the boat to the up
            } else if (direction == "u") {
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
                        std::cout << Ships[counter].GetName() << " overlaps another ship, please try again" <<std::endl;
                        DirectionValid = false;
                        overlap = false;
                        upvalid = false;
                    }
                }   else {
                            std::cout << Ships[counter].GetName() << " goes outside the range of the board, please try again" <<std::endl;
                            DirectionValid = false;
                            upvalid = false;
                        }
            }
        }
        //If there are no valid placement directions (ie the boat is stuck) it says the boat is stuck and resets asking once again
        if (rightvalid == false && leftvalid == false && upvalid == false && downvalid == false) {
            std::cout << "Your ship is trapped and cannot go here" << std::endl;
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

void Player::Move(User* opponent){

    std::string x1 = "";
    std::string y1 = "";

    int x = 0;
    int y = 0;

    bool xvalid = false;
    bool yvalid = false;

    bool z = true;
    while (z) {

        //Takes in the users x coordinate and checks if it is an integer, if not it asks again
        if (xvalid == false) {
            std::cout << "Please input the x-coordinate between 0 to 9 to hit, or 10 to quit" << std::endl;
            std::cin >> x1;
            for(int i = 0; i < x1.length(); i++) {
                if(isdigit(x1[i]) == false) {
                    std::cout << "Invalid input: please input a number between 0 to 9, or 10 to quit" << std::endl;
                    break;
                } else {
                    xvalid = true;
                }
            }
        }

        //If the x input is a number, checks if it is between 0 and 9, if not it asks again
        if(xvalid == true) {
            x = std::stoi(x1);
            if (x < 0 || x > 10) {
                xvalid = false;
                std::cout << "Invalid input: please input a number between 0 to 9, or 10 to quit" << std::endl;
            }
        }
        if(xvalid == true && x == 10) {
            for(int i =0;i<5;i++){
            Ships[i].Sink();
            ((*opponent).GetShips())[i].Sink();
            }
            return;
        }

       //If the x input is valid, asks for the y input, and if it is not an integer asks again
        if(xvalid == true && yvalid == false) {
            std::cout << "Please input the y-coordinate between 0 to 9 to hit" << std::endl;
            std::cin >> y1;
            for(int i = 0; i < y1.length(); i++) {
                if(isdigit(y1[i]) == false) {
                    std::cout << "Invalid input: please input a number between 0 to 9" << std::endl;
                    break;
                } else {
                    yvalid = true;
                }
            }
        }

        //If the y input is valid, checks if it is between 0 and 9, if not it asks again
        if(xvalid == true && yvalid == true) {
            y = std::stoi(y1);
            if (y < 0 || y > 9) {
                yvalid = false;
                std::cout << "Invalid input: please input a number between 0 to 9" << std::endl;
            }
        }
        if(xvalid == true && yvalid == true) {
            if(HitBoard[x][y] != 0) {
                std::cout<< "Please put in coordinates you have not hit" <<std::endl;
                xvalid = false;
                yvalid = false;
            }
        }

        //If both inputs are valid, attempts to hit that spot
        if(xvalid == true && yvalid == true) {
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
            }
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