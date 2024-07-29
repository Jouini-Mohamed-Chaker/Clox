CC = gcc
CFLAGS = -Wall -Wextra -std=c11
OBJ = main.o memory.o chunk.o

clox: $(OBJ)
	$(CC) $(OBJ) -o clox

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o clox
