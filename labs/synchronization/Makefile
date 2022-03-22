all: count count_ticket start greet

count: count.cpp
	g++ -o count count.cpp -pthread

count_ticket: count_ticket.cpp
	g++ -o count_ticket count_ticket.cpp -pthread

start: start.cpp
	g++ -o start start.cpp -pthread

greet: greet.cpp
	g++ -o greet greet.cpp -pthread

clean:
	rm -f count count_ticket start greet
