BIN=Animal

CC=c++
CFLAGS= -std=c++98
CFLAGS += -g3

SRC_DIR=./Src/
SRC_FILES= main.cpp			\
		   Animal.cpp		\
		   Dog.cpp			\
		   Cat.cpp			\
		   WrongAnimal.cpp	\
		   WrongCat.cpp		\
		   Brain.cpp
SRC=$(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_DIR=./Objs/
OBJS=$(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SRC))

INC_DIR=./Inc/
INC_FILES= Animal.hpp		\
		   Dog.hpp			\
		   Cat.hpp			\
		   WrongAnimal.hpp	\
		   WrongCat.hpp		\
		   Brain.hpp
INC=$(addprefix $(INC_DIR), $(INC_FILES))

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
