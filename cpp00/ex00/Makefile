CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
CC = c++
RM = rm -f
SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)
NAME = megaphone

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(NAME)