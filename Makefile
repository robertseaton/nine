CC = clang
CFLAGS = -O0 -ggdb -march=native -pipe -Wall -Wextra
objects = main.o execute.o

all : nine
nine : $(objects)
	$(CC) $(CFLAGS) -o nine $(objects) -I.

