CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -g3
CC = c++
RM = rm -f
SRC = Fixed.cpp \
	main.cpp
OBJ = $(SRC:.cpp=.o)
NAME = Fixed

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(OBJ)
	$(RM) $(NAME)

re: clean all