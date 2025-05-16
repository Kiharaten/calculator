#Makefile

all:
	gcc -o main.o \
	src/main.c \
	src/functions.c

clean:
	rm -f \
	*.o \
	*.a \
	*.out