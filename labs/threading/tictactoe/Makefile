all: game

CXX=g++
CXXFLAGS=-std=c++11 -pthread

game: game.cpp
	$(CXX) $(CXXFLAGS) -g -o game game.cpp

clean:
	rm -f *.o game
