flags=-O2 -Wall -Wextra -std=c2x
ldflags=

.PHONY: all clean

all: clean PRJNM

PRJNM: PRJNM.o
	cc $(flags) $^ -o $@ $(ldflags)

PRJNM.o: PRJNM.c PRJNM.h
	cc $(flags) -c $<

clean:
	rm -f *.o PRJNM