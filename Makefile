#Makefile

all:
	gcc src/main.c -o main.o

clean:
	rm -f *.o *.a *.out