CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
CXX = c++
RM = rm -f
SRC = main.cpp \
	PmergeMe.cpp
OBJ = $(SRC:.cpp=.o)
NAME = PmergeMe

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(OBJ)
	$(RM) $(NAME)

re: clean all