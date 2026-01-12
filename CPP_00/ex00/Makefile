BIN=megaphone

CC= c++
CFLAGS = -Werror -Wall -Wextra -std=c++98

SRC_FILE= megaphone.cpp
SRC_DIR=./Src/
OBJ_DIR=./Obj/

SRC:= $(addprefix $(SRC_DIR), $(SRC_FILE))
OBJS := $(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SRC))

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(INC)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(BIN)

re: fclean all
