CC = clang
CFLAGS = -Wall -Wextra -std=c11
OBJ = main.o memory.o chunk.o debug.o value.o

clox: $(OBJ)
	$(CC) $(OBJ) -o clox

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o clox
