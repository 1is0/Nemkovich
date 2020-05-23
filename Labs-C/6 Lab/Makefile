all: build run clean
LR6.o: Program.c Tree.c Tree.h
	gcc -c -o LR6.o Program.c Tree.c Tree.h
build: LR6.o
	gcc -o LR6 LR6.o
run:
	LR6.exe
clean:
	del *.o LR6
