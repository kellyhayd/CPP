NAME	= accounts

CXX			:= c++
CXXFLAGS	:= -Wall -Werror -Wextra -std=c++98
SRCDIR		:= src/
SRC			:= $(addprefix $(SRCDIR), \
				Account.cpp \
				tests.cpp)
OBJ			:= $(SRC:%.cpp=%.o)
INCLUDE		:= -Iinclude/
RM			= rm -f

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
