all: build run clean
LR5.o: Program.c Functions.c Functions.h
	gcc -c -o LR5.o Program.c Functions.c Functions.h
build: LR5.o
	gcc -o LR5 LR5.o
run:
	LR5.exe
clean:
	del *.o LR5
