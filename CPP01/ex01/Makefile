NAME		= BrainZ

CXX			:= c++
CXXFLAGS	:= -Wall -Werror -Wextra -std=c++98

SRCDIR		:= src/
SRC			:= $(addprefix $(SRCDIR), \
				Zombie.cpp \
				zombieHorde.cpp \
				main.cpp)

OBJ			:= $(SRC:%.cpp=%.o)
INCLUDE		:= -Iinclude
RM			:= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
