NAME	= phonebook

CXX			:= c++
CXXFLAGS	:= -Wall -Werror -Wextra -std=c++98
SRCDIR		:= src/
SRC			:= $(addprefix $(SRCDIR), \
				PhoneBook.cpp \
				Contact.cpp \
				main.cpp)
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
