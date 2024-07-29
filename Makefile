CC = gcc
CFLAGS = -Wall -Wextra -std=c11
OBJ = main.o chunk.o memory.o

my_project: $(OBJ)
    $(CC) $(OBJ) -o clox

%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -f *.o clox
