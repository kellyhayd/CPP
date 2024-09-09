NAME	= megaphone

CC		= g++
CCFLAGS	= -Wall -Werror -Wextra
SRC		= megaphone.cpp
OBJ		= $(SRC:%.cpp=%.o)
RM		= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
