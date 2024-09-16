NAME	= phonebook

CXX			= c++
CXXFLAGS	= -Wall -Werror -Wextra
SRC			= phonebook.cpp
OBJ			= $(SRC:%.cpp=%.o)
RM			= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
