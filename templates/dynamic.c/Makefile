CC=cc
CFLAGS=-O2 -Wall -Wextra -std=c2x -fPIC
LDFLAGS=-shared
LINKFLAGS=-L. -Wl,-rpath=.

LIB_NAME=libPRJNM.so
EXE_NAME=test


.PHONY: all clean

all: clean $(LIB_NAME) $(EXE_NAME)

$(LIB_NAME): PRJNM.o
	$(CC) $(LDFLAGS) -o $@ $^ 

$(EXE_NAME): test.o  $(LIB_NAME)
	$(CC) $(CFLAGS) $^ -o $@ $(LINKFLAGS)

PRJNM.o: PRJNM.c PRJNM.h
	$(CC) $(CFLAGS) -c $<


test.o: test.c PRJNM.h
	$(CC) $(CFLAGS) -c $< -L. -Wl,-rpath=. -lPRJNM

clean:
	rm -f *.o $(LIB_NAME) $(EXE_NAME)