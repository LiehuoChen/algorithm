CC=g++
CVERSION=-std=c++11
DEBUG=-g
CFLAGS=-Wall -Wextra $(DEBUG) $(CVERSION)

all: kmp hello merge quick

kmp: kmp.o
	$(CC) -o $@ $^ $(CFLAGS)
hello: hello.o
	$(CC) -o $@ $^ $(CFLAGS)
merge: mergeSort.o
	$(CC) -o $@ $^ $(CFLAGS)
quick: quickSort.o
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.cpp
	$(CC) -c $(CFLAGS) -o $@ $^


clean: 
	rm *.o kmp



