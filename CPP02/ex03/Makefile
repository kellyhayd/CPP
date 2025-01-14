.SILENT:

NAME := BSP

CXX := g++
CXXFLAGS :=  -Wall -Werror -Wextra -std=c++98

INCLUDE := -Iinclude/
SRCDIR := src/
SRC := $(addprefix $(SRCDIR), \
		main.cpp \
		Fixed.cpp \
		Point.cpp \
		bsp.cpp)
OBJ := $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all fclean re
