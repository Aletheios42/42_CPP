BIN =  RPN

CC = c++
CFLAGS= -Wall -Wextra -Werror -std=c++98

ifeq ($(SANITIZE),1)
	CFLAGS += -g3 -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer
endif

SRC_DIR = ./Src/
SRC_FILES = main.cpp \
            RNP.cpp
SRC := $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_DIR = ./Obj/
OBJ := $(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SRC))

INC_DIR = ./Inc/
INC_FILES = RNP.hpp
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

test: all
	@echo "--- Test 1: Básicos (3+4)*2 ---"
	@echo "Esperado: 14"
	./$(BIN) "3 4 + 2 *"

	@echo "\n--- Test 2: División y Resta (9/3)-2 ---"
	@echo "Esperado: 1"
	./$(BIN) "9 3 / 2 -"

	@echo "\n--- Test 3: Multiplicación con resultado grande (8*9) ---"
	@echo "Esperado: 72"
	./$(BIN) "8 9 *"

	@echo "\n--- Test 4: Operaciones anidadas 5 + ((1+2)*4) - 3 ---"
	@echo "Esperado: 14"
	./$(BIN) "5 1 2 + 4 * + 3 -"