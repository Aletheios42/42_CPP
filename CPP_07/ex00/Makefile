BIN=Templates

CC=c++
CFLAGS= -Wall -Wextra -Werror -std=c++98

SRC_DIR=./Src/
SRC_FILES=main.cpp
SRC:=$(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_DIR=./Obj/
OBJ:=$(patsubst $(OBJ_DIR)%.o, $(SRC_DIR)%.cpp, $(SRC))

INC_DIR=./Inc/
INC_FILES=whatever.hpp
INC:=$(addprefix $(INC_DIR), $(INC_FILES))

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(INC)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean:
	rm -f $(BIN)

re: fclean all

leaks: all
	valgrind --leak-check=full ./$(BIN)