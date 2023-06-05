CC = gcc
CFLAGS=-Werror -I.
DEPS = snake.h gameboard.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

snake: snake.o gameboard.o engine.o
	$(CC) -o snake snake.o gameboard.o engine.o

