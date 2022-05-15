BRANCH = Version1
SRCS = Ship.h Ship.cpp TestShip.cpp Makefile
BIN = f11 f14
CC = g++
FLAGS = -Wall -Wextra -pedantic -std=c++14

all:

TestShip: Ship.cpp TestShip.cpp
	$(CC) Ship.cpp TestShip.cpp -o TestShip $(FLAGS)
	./TestShip

upload: $(SRCS)
	git add $(SRCS)
	git commit -m "Make file add"
	git push origin $(BRANCH)

clean:
	rm -f $(BIN)