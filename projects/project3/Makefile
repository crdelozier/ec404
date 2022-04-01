CFLAGS=-g

all: benchmark.o test.o mymalloc.o
	g++ -o benchmark benchmark.o mymalloc.o
	g++ -o test test.o mymalloc.o

test.o: test.c
	gcc -c test.c $(CFLAGS)

benchmark.o: benchmark.c
	gcc -c benchmark.c $(CFLAGS)

mymalloc.o: mymalloc.cpp
	g++ -c mymalloc.cpp $(CFLAGS)

clean:
	rm -f *.o test benchmark
