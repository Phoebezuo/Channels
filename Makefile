CC=clang
CFLAGS=-Werror=vla -Wextra -Wall -Wshadow -Wswitch-default -std=c11 -g
CFLAG_SAN=$(CFLAGS) -fsanitize=address

.PHONY: clean

clean:
	rm -f *.o
	rm -f all

channel.o: channel.c 
	$(CC) -c $(CFLAGS) $^ -o $@

main.o: main.c
	$(CC) -c $(CFLAGS) $^ -o $@

all: main.o channel.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@
	./all