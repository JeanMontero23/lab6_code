# Se define el compilador y flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Se define el ejecutable objetivo
all: main

# Se hace la regla para poder enlazar los archivos object y se crea el ejecutable
main: main.o stack.o
	$(CC) $(CFLAGS) -o main main.o stack.o

# Se crea regla para compilar main.c
main.o: main.c stack.h
	$(CC) $(CFLAGS) -c main.c

# Se crea regla para compilar stack.c
stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

# Se crea regla para limpiar los archivos generados
clean:
	rm -f *.o main
