CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -g3
CXX = c++
RM = rm -f
SRC = Bureaucrat.cpp \
	main.cpp
OBJ = $(SRC:.cpp=.o)
NAME = ex00

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(OBJ)
	$(RM) $(NAME)

re: clean all