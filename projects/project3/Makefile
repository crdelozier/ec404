CXXFLAGS=-g

all: benchmark.o test.o mymalloc.o
	g++ -o benchmark benchmark.o mymalloc.o
	g++ -o test test.o mymalloc.o

test.o: test.c
	g++ -c test.c $(CXXFLAGS)

benchmark.o: benchmark.c
	g++ -c benchmark.c $(CXXFLAGS)

mymalloc.o: mymalloc.cpp
	g++ -c mymalloc.cpp $(CXXFLAGS)

clean:
	rm -f *.o test benchmark mymalloc.so
