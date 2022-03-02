all: stats

CXX=g++
CXXFLAGS=-std=c++11 -pthread

stats: stats.cpp
	$(CXX) $(CXXFLAGS) -g -o stats stats.cpp

clean:
	rm -f *.o stats
