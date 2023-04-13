.PHONY: all clean

all : MatrixCalculator

MatrixCalculator : main.o operations.o 
	gcc main.o operations.o -o MatrixCalculator

main.o : main.c
	gcc -c main.c

operations.o : operations.c
	gcc -c operations.c 

clean:
	rm -f main.o operations.o
