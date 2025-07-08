BIN=Form

CC= c++
CFLAGS= -std=c++98

SRC_DIR=./Src/
SRC_FILES=main.cpp				\
		  Bureaucrat.cpp		\
		  Form.cpp
SRC:=$(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_DIR=./Objs/
OBJ:=$(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SRC))

INC_DIR=./Inc/
INC_FILES=Bureaucrat.hpp		\
		  Form.hpp
INC:=$(addprefix $(INC_DIR), $(INC_FILES))

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(INC)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(BIN)
