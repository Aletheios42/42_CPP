BIN=Fixed

CXX=c++
CXXFLAGS= -Wall -Werror -Wextra -std=c++98

SRC_FILES= main.cpp 	\
	   Fixed.cpp

SRC_DIR=./Src/
SRC=$(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_DIR=./Obj/
OBJ=$(patsubst $(SRC_DIR)%.cpp,  $(OBJ_DIR)%.o, $(SRC))

INC_FILES= Fixed.hpp 	\

INC_DIR=./Inc/
INC=$(addprefix $(INC_DIR), $(INC_FILES))

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(BIN)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(INC)
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(BIN)

re: fclean all
