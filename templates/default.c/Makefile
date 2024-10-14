CC=cc
CFLAGS=-O2 -Wall -Wextra -std=c2x
LDFLAGS=

.PHONY: all clean

all: clean PRJNM

PRJNM: PRJNM.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

PRJNM.o: PRJNM.c PRJNM.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o PRJNM