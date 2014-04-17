CC = g++
CFLAG = -Wall -g

all: editdistance

editdistance: main.o EditDistance.o 
	$(CC) $(CFLAG) main.o EditDistance.o -o main

main.o: main.cpp
	$(CC) $(CFLAG)  -c main.cpp 
	
EditDistance.o: EditDistance.cpp EditDistance.h
	$(CC) $(CFLAG) -c EditDistance.cpp 

clean:
	rm *.o main.exe
