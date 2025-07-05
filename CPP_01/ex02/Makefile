BIN=references
CC=c++
CFLAGS= -std=c++98 -g3

SRC_FILES = main.cpp 
SRC := $(addprefix $(SRC_DIR), $(SRC_FILES))
SRC_DIR=Src/

OBJ_DIR=Obj/
OBJS := $(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SRC))

INC_FILES = Zombie.hpp
INC := $(addprefix $(INC_DIR), $(INC_FILES))

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
fclean: clean
	rm -f $(BIN)

