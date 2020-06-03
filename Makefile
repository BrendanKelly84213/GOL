LDLIBS=-lglut -lGLEW -lGL -lSDL2 
CFLAGS = -std=c++11 -g -Wall -O3 -O0

SRC1 = window.cpp main.cpp grid.cpp
test: $(SRC1) window.h grid.h
	g++ $(CFLAGS) -o test $(SRC1) $(LDLIBS)
