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
	mkdir -p ebin/
	cp binary16.c binary16.h ebin/
	erl -make
	erl -eval "make:all([{parse_transform, eqc_cover}])" -s init stop

clean:
	rm -f *.o
	rm -f *.bin
