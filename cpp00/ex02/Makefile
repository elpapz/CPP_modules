CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -g3
CC = c++
RM = rm -f
SRC = Account.cpp \
	tests.cpp
OBJ = $(SRC:.cpp=.o)
NAME = myaccount

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(NAME)