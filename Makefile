BRANCH = Version1
SRCS = Ship.h Ship.cpp TestShip.cpp Makefile User.h User.cpp TestUser.cpp Player.h Player.cpp
CC = g++
FLAGS = -Wall -Wextra -pedantic -std=c++14


TestShip: Ship.cpp TestShip.cpp
	$(CC) Ship.cpp TestShip.cpp -o TestShip $(FLAGS)
	./TestShip

TestUser: Ship.cpp User.cpp TestUser.cpp
	$(CC) Ship.cpp User.cpp TestUser.cpp -o TestUser $(FLAGS)
	./TestUser

Game: Ship.cpp User.cpp Player.cpp Computer.cpp Main.cpp
	$(CC) Ship.cpp User.cpp Player.cpp Computer.cpp Main.cpp -o Game
	./Game