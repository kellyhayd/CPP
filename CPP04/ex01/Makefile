.SILENT:

NAME	:= Brain

CXX			:= g++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++98

INCLUDE	:= -Iinclude/
SRCDIR	:= src/
SRC		:= $(wildcard $(SRCDIR)*.cpp)
OBJ		:= $(SRC:%.cpp=%.o)

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
