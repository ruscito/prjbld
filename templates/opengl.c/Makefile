# flags=-O2 -Wall -Wextra -std=c2x
# ldflags=-lGL -ldl -lglfw

CC = clang
CFLAGS = -Wall -Wextra -std=c11 -Iinclude -I/usr/local/include
LDFLAGS = -L/usr/local/lib -lglfw -framework OpenGL

# Directories
OBJ_DIR = obj
BIN_DIR = bin

# Create directories if they don't exist
$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

.PHONY: all clean

all: clean $(BIN_DIR)/PRJNM

$(BIN_DIR)/PRJNM: $(OBJ_DIR)/PRJNM.o $(OBJ_DIR)/glad.o
	$(CC) $(CFLAGS) -o $@  $^ $(LDFLAGS)

$(OBJ_DIR)/PRJNM.o: PRJNM.c PRJNM.h 
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/glad.o: src/glad.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/PRJNM