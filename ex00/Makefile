NAME	= megaphone

CXX			= c++
CXXFLAGS	= -std=c++98 -Wall -Werror -Wextra
SRC			= megaphone.cpp
OBJ			= $(SRC:%.cpp=%.o)
RM			= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
