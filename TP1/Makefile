
execute: main.o
		gcc -Wall -pedantic -o execute main.o

main.o: main.c functionsFS.h
		gcc -Wall -pedantic -c main.c

clean:
		rm -f execute *.o	