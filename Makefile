BRANCH = Version1
SRCS = Ship.h Ship.cpp TestShip.cpp Makefile
CC = g++
FLAGS = -Wall -Wextra -pedantic -std=c++14

all:

TestShip: Ship.cpp TestShip.cpp
	$(CC) Ship.cpp TestShip.cpp -o TestShip $(FLAGS)
	./TestShip

TestUser: Ship.cpp User.cpp TestUser.cpp
	$(CC) Ship.cpp User.cpp TestUser.cpp -o TestUser $(FLAGS)
	./TestUser

upload: $(SRCS)
	git add $(SRCS)
	git commit -m "Make file add"
	git push origin $(BRANCH)