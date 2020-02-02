all: generate threads

CXX=g++
CXXFLAGS=-std=c++11

generate:
	$(CXX) $(CXXFLAGS) -g -o generate generate.cpp

threads:
	$(CXX) $(CXXFLAGS) -g -o threads threads.cpp

clean:
	rm -f *.o generate threads
