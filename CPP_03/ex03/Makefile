BIN=DiamondTrap

CC= c++ 
CFLAGS= -std=c++98

SRC_FILES= main.cpp			\
		   ClapTrap.cpp		\
		   ScavTrap.cpp		\
		   FragTrap.cpp		\
		   DiamondTrap.cpp		
SRC_DIR=./Src/
SRC:=$(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_DIR=./Objs/
OBJS:=$(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SRC))

INC_FILES=ClapTrap.hpp 		\
		  ScavTrap.hpp		\
		  FragTrap.hpp		\
		  DiamondTrap.hpp
INC_DIR=./Inc/
INC:=$(addprefix $(INC_DIR), $(INC_FILES))

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(BIN)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(INC)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(BIN)
