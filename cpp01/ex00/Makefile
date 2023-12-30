CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
CXX = c++
RM = rm -f
SRC = randomChump.cpp \
	newZombie.cpp \
	Zombie.cpp \
	main.cpp
OBJ = $(SRC:.cpp=.o)
NAME = zombies

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(OBJ)
	$(RM) $(NAME)

re: clean all

.PHONY: all clean re