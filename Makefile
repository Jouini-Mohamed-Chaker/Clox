CC = clang
CFLAGS = -Wall -Wextra -std=c11

# Automatically find all .c files in the current directory
SRC = $(wildcard *.c)

# Replace .c with .o to get the list of object files
OBJ = $(patsubst %.c,%.o,$(SRC))

clox: $(OBJ)
	$(CC) $(OBJ) -o clox

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o clox
