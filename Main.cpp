#include "Player.cpp"
#include "Computer.cpp"
#include <iostream>

int main() {

    std::string choice;

    std::cout << "Do you want to play against another player or against a computer (player or computer)" << std::endl;
    cin >> choice;

    if (choice == "player") {

        User* Player1 = new Player;
        User* Player2 = new Player;

        while(Player2->WinCondition(Player1) != true) {
            Player1.move()
            if(Player1->WinCondition(Player2) == true) {
                break;
            }
            Player2.move()
        }

    } else if(choice == "computer") {
        User* Player1 = new Player;
        User* Computer1 = new Computer;

        while(Computer1->WinCondition(Player1) != true) {
            Player1.move()
            if(Player1->WinCondition(Computer1) == true) {
                break;
            }
            Computer1.move()
        }
    }

    return 0;
}