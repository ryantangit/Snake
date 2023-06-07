CC = gcc
CFLAGS=-Werror -I.
DEPS = snake.h gameboard.h util.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

snake: snake.o gameboard.o engine.o util.o
	$(CC) -o snake snake.o gameboard.o engine.o util.o

