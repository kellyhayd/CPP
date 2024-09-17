NAME	= phonebook

CXX			= c++
CXXFLAGS	= -Wall -Werror -Wextra
SRC			= phonebook.cpp
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
