#include "Player.h"
#include "Computer.h"
#include <iostream>

int main() {

    std::string choice;

    std::cout << "Do you want to play against another player or against a computer (player or computer)" << std::endl;
    std::cin >> choice;

    if (choice == "player") {
        User* Player1 = new Player;
        User* Player2 = new Player;

        while(Player2->WinCondition(Player1) != true) {
            Player1->DisplayBoard(Player2);
            Player1->Move(Player2);
            if(Player1->WinCondition(Player2) == true) {
                break;
            }
            Player2->DisplayBoard(Player1);
            Player2->Move(Player1);
        }

        delete Player1;
        delete Player2;
    } else if(choice == "computer") {

        User* Player1 = new Player;
        User* Computer1 = new Computer;

        while(Computer1->WinCondition(Player1) != true) {
            Player1->DisplayBoard(Computer1);
            Player1->Move(Computer1);
            if(Player1->WinCondition(Computer1) == true) {
                break;
            }
            //Computer1->DisplayBoard();
            Computer1->Move(Player1);
        }

        delete Player1;
        delete Computer1;
    }

    return 0;
}