CC = gcc
CFLAGS = -Wall -Wextra

all: main_program

main_program: main.o quick-sort.o
	$(CC) $(CFLAGS) -o main_program main.o quick-sort.o

main.o: main.c quick-sort.h
	$(CC) $(CFLAGS) -c -o main.o main.c

quick-sort.o: quick-sort.c quick-sort.h
	$(CC) $(CFLAGS) -c -o quick-sort.o quick-sort.c

clear:
	del /Q main_program.exe *.o
