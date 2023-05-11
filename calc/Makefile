.PHONY: all clean

all : MatrixCalculator

MatrixCalculator : main.o Operations.o 
	gcc main.o Operations.o -o MatrixCalculator

main.o : main.c
	gcc -c main.c

Operations.o : Operations.c
	gcc -c Operations.c 

clean:
	rm -f main.o Operations.o