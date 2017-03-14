.PHONY: all clean gdb-*

OBJS=binary16.o

CFLAGS=-Werror -Wextra -pedantic -std=c11 -g -O0

all: main.bin

%.o: %.c Makefile
	gcc $(CFLAGS) -c $< -o $@

%.bin: %.c $(OBJS) Makefile
	gcc $(CFLAGS) $(OBJS) $< -o $@

gdb-%.bin: %.bin Makefile
	gdb -q -x run.gdb $<

test:
	mkdir -p ebin
	erl -make

clean:
	rm -f *.o
	rm -f *.bin
