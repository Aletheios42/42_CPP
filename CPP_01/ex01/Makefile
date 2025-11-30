BIN=Zombie
CC=c++
CFLAGS= -std=c++98 -g3

SRC_FILES = main.cpp \
            Zombie.cpp \
            newZombie.cpp

SRC_DIR=Src/
OBJ_DIR=Obj/
INC_FILES = Zombie.hpp	\

INC_DIR=Inc/

SRC := $(addprefix $(SRC_DIR), $(SRC_FILES))
INC := $(addprefix $(INC_DIR), $(INC_FILES))
OBJS := $(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SRC))

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(INC)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
fclean: clean
	rm -f $(BIN)

