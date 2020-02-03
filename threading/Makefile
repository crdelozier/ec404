all: generate threads

CXX=g++
CXXFLAGS=-std=c++11

generate: generate.cpp
	$(CXX) $(CXXFLAGS) -g -o generate generate.cpp

threads: threads.cpp
	$(CXX) $(CXXFLAGS) -g -o threads threads.cpp

clean:
	rm -f *.o generate threads
