CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
CC = c++
RM = rm -f
SRC = Contact.cpp \
	main.cpp
OBJ = $(SRC:.cpp=.o)
NAME = myPhoneBook

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(NAME)