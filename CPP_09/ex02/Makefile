BIN = PmergeMe 

CC = c++
CFLAGS= -Wall -Wextra -Werror -std=c++98

ifeq ($(SANITIZE),1)
	CFLAGS += -g3 -fsanitize=address
endif

SRC_DIR = ./Src/
SRC_FILES = main.cpp \
            PmergeMe.cpp
SRC := $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_DIR = ./Obj/
OBJ := $(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SRC))

INC_DIR = ./Inc/
INC_FILES = PmergeMe.hpp

INC := $(addprefix $(INC_DIR), $(INC_FILES))

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(INC)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

sanitize:: fclean
	@$(MAKE) SANITIZE=1 all

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(BIN)

re: fclean all

leaks: all
	valgrind --leak-check=full ./$(BIN)
