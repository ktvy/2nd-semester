.PHONNY: all clean

all: String

String: main.o StringFunctions.o
	gcc main.o StringFunctions.o -o String

main.o: main.c
	gcc -c main.c 

StringFunctions.o: StringFunctions.c
	gcc -c StringFunctions.c 

clean: 
	rm -f main.o StringFunctions.o