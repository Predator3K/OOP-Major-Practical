#include "Player.h"
#include "Computer.h"
#include <iostream>

int main() {

    //std::string choice;

    //std::cout << "Do you want to play against another player or against a computer (player or computer)" << std::endl;
    //std::cin >> choice;

    //Player player1;
    //player1.DisplayBoard();
    //Computer computer1;
    //computer1.DisplayBoard();


        /*User* Player1 = new Player;
        User* Player2 = new Player;

        while(Player2->WinCondition(Player1) != true) {
            (*Player1).DisplayBoard();
            Player1->Move(Player2);
            if(Player1->WinCondition(Player2) == true) {
                break;
            }
            (*Player2).DisplayBoard();
            Player2->Move(Player1);
        }*/

        User* Computer2 = new Computer;
        User* Computer1 = new Computer;

        while(Computer2->WinCondition(Computer1) != true) {
            Computer1->DisplayBoard();
            Computer1->Move(Computer2);
            if(Computer1->WinCondition(Computer2) == true) {
                break;
            }
            Computer2->DisplayBoard();
            Computer2->Move(Computer1);
        }

    delete Computer1;
    delete Computer2;

    return 0;
}