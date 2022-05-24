#include "User.h"
#include <cstring>
#include <iostream>
#include <chrono>
#include <ctime>

User::User() {
    memset(ShipBoard, 0, sizeof(ShipBoard));
    start = std::chrono::system_clock::now();
    Ships = new Ship[5];

    new(&Ships[0]) Ship("Flagship", 6);
    new(&Ships[1]) Ship("Destroyer", 5);
    new(&Ships[2]) Ship("Carrier", 4);
    new(&Ships[3]) Ship("Submarine", 3);
    new(&Ships[4]) Ship("Scout Boat", 2);

    HitBoard = new int*[10];
        for (int i = 0; i < 10; i++) {
            HitBoard[i] = new int[10];
        }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            HitBoard[i][j] = 0;
        }
    }
}

Ship* User::GetShips() {
    return Ships;
}

int** User::GetHitBoard() {
    return HitBoard;
}

bool User::WinCondition(User* opponent) {
    int ShipsSunk = 0;
    for (int i = 0; i < 5; i++) {
            if ((*opponent).Ships[i].IsSunk() == true) {
                ShipsSunk++;
        }
    }

    if (ShipsSunk == 5) {
        return true;
    }

    return false;
}

int User::GameTimer(){
    std::chrono::time_point<std::chrono::system_clock> end;
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "time passed: " << elapsed_seconds.count() << "s\n";
    return 0;
}

User::~User() {
    delete[] Ships;
    for (int i  = 0; i < 10; i++) {
        delete[] HitBoard[i];
    }
    delete[] HitBoard;
}
