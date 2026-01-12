BIN=ScavTrap

CXX= c++ 
CXXFLAGS= -Wall -Wextra -Werror -std=c++98

SRC_FILES= main.cpp			\
		   ClapTrap.cpp		\
		   ScavTrap.cpp		
SRC_DIR=./Src/
SRC:=$(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_DIR=./Objs/
OBJS:=$(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SRC))

INC_FILES=ClapTrap.hpp \
		  ScavTrap.hpp
INC_DIR=./Inc/
INC:=$(addprefix $(INC_DIR), $(INC_FILES))

all: $(BIN)

$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(BIN)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(INC)
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $(@)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(BIN)

re: fclean all
