
CC=gcc
CFLAGS=-I.
DEPS = dictonary.h stack.h mini_forth.h
OBJ = dictionary.o stack.o mini_forth.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

mini_forth: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
