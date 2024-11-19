NAME		:= harl_2.0

CXX			:= g++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++98

INCLUDE	:= -Iinclude
SRCDIR	:= src/
SRC		:= $(addprefix $(SRCDIR), \
		main.cpp \
		Harl.cpp)

OBJ		= $(SRC:%.cpp=%.o)
RM		:= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
