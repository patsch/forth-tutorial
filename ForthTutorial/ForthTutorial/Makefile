
CC=gcc
CFLAGS=-I.
DEPS = dictonary.h stack.h forth.h main.h
OBJ = dictionary.o stack.o forth.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

mini_forth: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
