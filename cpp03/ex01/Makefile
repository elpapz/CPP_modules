CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -g3
CC = c++
RM = rm -f
SRC = ClapTrap.cpp \
	ScavTrap.cpp \
	main.cpp
OBJ = $(SRC:.cpp=.o)
NAME = ScavTrap

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(OBJ)
	$(RM) $(NAME)

re: clean all