BIN=sed

CXX=c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98

SRC_FILES= main.cpp 	\

SRC_DIR=./Src/
SRC=$(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_DIR=./Obj/
OBJ=$(patsubst $(SRC_DIR)%.cpp,  $(OBJ_DIR)%.o, $(SRC))

INC_FILES= sed.hpp 	\

INC_DIR=./Inc/
INC=$(addprefix $(INC_DIR), $(INC_FILES))


all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(BIN)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(INC)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(BIN)
