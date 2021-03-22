all: count start

count: count.cpp mutex.hpp ticket.hpp
	g++ -o count count.cpp -pthread

start: start.cpp barrier.hpp
	g++ -o start start.cpp -pthread

clean:
	rm -f count start
