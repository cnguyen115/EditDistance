CC = g++
CFLAG = -Wall -g
LDFLAG = -lboost_unit_test_framework

all: editdistance

editdistance: EditDistance.o 
	$(CC) $(CFLAG) EditDistance.o -o editdistance

EditDistance.o: EditDistance.cpp EditDistance.h
	$(CC) $(CFLAG) -c EditDistance.cpp 

clean:
	rm *.o editdistance 