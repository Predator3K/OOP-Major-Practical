#include "User.h"
#include <iostream>

//This only works if the virtual function is commented out. Simply shows the constructor and deconstructor for user work correctly as well as correctly checking if a player wins
int main() {
    User user1;
    User user2;
    User* user_ptr= &user2;

    std::cout << user1.WinCondition(user_ptr) << std::endl; 
    return 0;
}