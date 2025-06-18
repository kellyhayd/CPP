.SILENT:

NAME	:= PmergeMe
CXX	:= c++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++98
INCLUDE	:= -Iinc/
SRCDIR	:= src/
SRC	:= $(addprefix $(SRCDIR), \
	PmergeMe.cpp \
	main.cpp)
BUILD	:= build/
OBJ	:= 	$(SRC:$(SRCDIR)%.cpp=$(BUILD)%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(BUILD)%.o: $(SRCDIR)%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf $(BUILD)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re