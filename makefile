CC = g++
FLAGS = -std=c++14 -Wall -c -g

linkedlist: linkedlist.o
	$(CC) -g linkedlist.o -o linkedlist

linkedlist.o: linkedlist.cpp linkedlist.h
	$(CC) $(FLAGS) linkedlist.cpp

clean:
	rm *.o linkedlist