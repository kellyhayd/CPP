NAME		:= Pointers

CXX			:= c++
CXXFLAGS	:= -Wall -Werror -Wextra -std=c++98

SRC			:= main.cpp
OBJ			:= main.o

RM			= rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
