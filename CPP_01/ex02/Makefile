BIN=references

CXX=c++
CXXFLAGS= -Werror -Wall -Wextra -std=c++98

SRC_FILES = main.cpp 
SRC_DIR=Src/
SRC :=$(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_DIR=Obj/
OBJS := $(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SRC))

INC_FILES = Zombie.hpp
INC := $(addprefix $(INC_DIR), $(INC_FILES))

all: $(BIN)

$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(BIN)

re: fclean all
