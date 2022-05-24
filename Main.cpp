#include "Player.h"
#include "Computer.h"
#include <iostream>
#include <chrono>
#include <thread>

int main() {

    std::string choice;
    bool choicevalid = true;

    std::cout << "Do you want to play against another player, against a computer or watch computer v computer? (player, computer, cvc)" << std::endl;
    while (choicevalid == true) {
        std::cin >> choice;
        if(choice == "player" || choice  == "computer" || choice == "cvc") {
            choicevalid = false;
        } else {
            std::cout << "Invalid choice please try again" << std::endl;
        }
    }

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

        if(Player2->WinCondition(Player1) == true) {
            std::cout << "Player 2 has won!" << std::endl;
        } else {
            std::cout << "Player 1 has won!" << std::endl;
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
            Computer1->Move(Player1);
        }

        if(Computer1->WinCondition(Player1) == true) {
            std::cout << "Computer has won!" << std::endl;
        } else {
            std::cout << "You have won!" << std::endl;
        }

        delete Player1;
        delete Computer1;

    } else if (choice == "cvc") {

        std::cout << "Do you want to see a fast game or slow game (f or s)" << std::endl;
        choicevalid = true;
        while (choicevalid == true) {
            std::cin >> choice;
            if(choice == "f" || choice  == "sr") {
                choicevalid = false;
            } else {
                std::cout << "Invalid choice please try again" << std::endl;
            }
        }
            if (choice == "f") {
                User* Computer1 = new Computer;
                User* Computer2 = new Computer;

                while(Computer2->WinCondition(Computer1) != true) {
                    std::cout << "Computer 1 board:" << std::endl;
                    Computer1->DisplayBoard(Computer2);
                    std::cout << "Computer 1 move:" << std::endl;
                    Computer1->Move(Computer2);
                    if(Computer1->WinCondition(Computer2) == true) {
                        break;
                    }
                    std::cout << "Computer 2 board:" << std::endl;
                    Computer2->DisplayBoard(Computer1);
                    std::cout << "Computer 2 move:" << std::endl;
                    Computer2->Move(Computer1);
                }

                if(Computer2->WinCondition(Computer1) == true) {
                    std::cout << "Computer 2 has won!" << std::endl;
                } else {
                    std::cout << "Computer 1 has won!" << std::endl;
                }

                delete Computer1;
                delete Computer2;
            }
            else if (choice == "s") {
                User* Computer1 = new Computer;
                User* Computer2 = new Computer;

                while(Computer2->WinCondition(Computer1) != true) {
                    std::this_thread::sleep_for (std::chrono::milliseconds(1000));
                    std::cout << "Computer 1 board:" << std::endl;
                    Computer1->DisplayBoard(Computer2);
                    std::cout << "Computer 1 move:" << std::endl;
                    Computer1->Move(Computer2);
                    if(Computer1->WinCondition(Computer2) == true) {
                        break;
                    }
                    std::this_thread::sleep_for (std::chrono::milliseconds(1000));
                    std::cout << "Computer 2 board:" << std::endl;
                    Computer2->DisplayBoard(Computer1);
                    std::cout << "Computer 2 move:" << std::endl;
                    Computer2->Move(Computer1);
                }

                if(Computer2->WinCondition(Computer1) == true) {
                    std::cout << "Computer 2 has won!" << std::endl;
                } else {
                    std::cout << "Computer 1 has won!" << std::endl;
                }

                delete Computer1;
                delete Computer2;
            }
    }

    return 0;
}