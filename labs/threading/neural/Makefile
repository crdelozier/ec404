all: neural

CXX=g++
CXXFLAGS=-std=c++11 -pthread

neural:	neural.cpp
	$(CXX) $(CXXFLAGS) -g -o neural neural.cpp

clean:
	rm -f *.o neural
