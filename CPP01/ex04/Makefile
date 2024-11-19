NAME		:= Sed

CXX			= g++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRC			:= main.cpp
OBJ			:= $(SRC:%.cpp=%.o)

rm			= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
