#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <cmath>
# include <sstream>
# include <cstdlib>
# include <exception>
# include <cstdlib>
#include <limits.h>

class RPN
{
    public:
        RPN(void);
        RPN(RPN const& copy);
        RPN& operator=(RPN const& copy);
        ~RPN(void);
        void validate_input(char *input);
        void convert(char *input);
        double calculations(double a, double b, char token);
        class WrongInputException : public std::exception
        {
            public:
              const char* what() const throw();
        };
    private:
        std::stack<double> _stack;
};

#endif
