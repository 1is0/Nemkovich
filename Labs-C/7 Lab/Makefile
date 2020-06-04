all: build run clean
LR7.o: lab7.c menu.c items.c menu.h items.h
	gcc -c -o LR7.o lab7.c menu.c items.c menu.h items.h
build: LR7.o
	gcc -o LR7 LR7.o
run:
	LR7.exe
clean:
	del *.o LR7
