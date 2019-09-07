all: project

project: main.o functions.c
	gcc main.c functions.c -o a.out

main.o: main.c
	gcc -c main.c

functions.o: functions.c
	gcc -c functions.c

clean:
	rm -rf *.o project
