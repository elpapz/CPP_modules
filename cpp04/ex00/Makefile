CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -g3
CXX = c++
RM = rm -f
SRC = ClapTrap.cpp \
	ScavTrap.cpp \
	FragTrap.cpp \
	main.cpp
OBJ = $(SRC:.cpp=.o)
NAME = Polymorphism

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(OBJ)
	$(RM) $(NAME)

re: clean all