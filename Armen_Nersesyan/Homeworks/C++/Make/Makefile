all: project

project: main.o trim.o bool.o
	gcc main.c trim.c bool.c -o trim.out

main.o: main.c
	gcc -c main.c

trim.o: trim.c
	gcc -c trim.c

bool.o:
	gcc -c bool.c

clean:
	rm -rf *.o project
