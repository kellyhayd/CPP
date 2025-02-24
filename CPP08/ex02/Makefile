.SILENT:

NAME = mutant

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

INCLUDE := -Iinclude/
SRCDIR := src/
SRC := $(addprefix $(SRCDIR), main.cpp)
OBJ := $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re