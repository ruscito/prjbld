# Compiler settings
CC = cc
CFLAGS = -Wall -Wextra -O2

# Raylib path (adjust these according to your setup)
RAYLIB_PATH = ./raylib
INCLUDES = -I$(RAYLIB_PATH)/src
LDFLAGS = -L$(RAYLIB_PATH)/src

# Platform detection
PLATFORM = $(shell uname)
ifeq ($(PLATFORM), Linux)
    LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
endif
ifeq ($(PLATFORM), Darwin)
    LIBS = -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
endif
ifeq ($(OS), Windows_NT)
    LIBS = -lraylib -lopengl32 -lgdi32 -lwinmm
endif

# Source files
SRC = PRJNM.c
OBJ = $(SRC:.c=.o)
EXEC = PRJNM

all: $(EXEC)

# Build raylib if not built
raylib:
	cd $(RAYLIB_PATH)/src && $(MAKE)

# Build the game
$(EXEC): $(OBJ) raylib
	$(CC) $(OBJ) $(LDFLAGS) $(LIBS) -o $(EXEC)

# Compile source files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean built files
clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all clean raylib