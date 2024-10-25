CC=cc
CFLAGS=-O2 -Wall -Wextra -std=c2x
LDFLAGS=-L. -lPRJNM
AR=ar
ARFLAGS=rcs

LIB_NAME=libPRJNM.a
EXE_NAME=test


.PHONY: all clean

all: clean $(LIB_NAME) $(EXE_NAME)

$(LIB_NAME): PRJNM.o
	$(AR) $(ARFLAGS) $@ $^ 

$(EXE_NAME): test.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

PRJNM.o: PRJNM.c PRJNM.h
	$(CC) $(CFLAGS) -c $<


test.o: test.c PRJNM.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o $(LIB_NAME) $(EXE_NAME)