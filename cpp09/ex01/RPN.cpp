#include "RPN.hpp"

RPN::RPN(){}

RPN::~RPN(){}

RPN::RPN(const RPN& copy)
{
	*this = copy;
}

RPN &RPN::operator=(RPN const& copy)
{
    (void)copy;
	return (*this);
}

void RPN::validate_input(char *input)
{
    std::string temp(input);
    //std::cout << "FUCK1\n";
    if (temp.find_first_not_of(" \t9876543210+-/*") != std::string::npos)
    {
        //std::cout << "FUCK2\n";
        throw WrongInputException(); 
    }
}

double RPN::calculations(double a, double b, char token)
{
    switch (token)
    {
        case '+':
        {
            return (a + b);
        }
        case '-':
        {
            return (a - b);
        }
        case '*':
        {
            return (a * b);
        }
        case '/':
        {
            return (a / b);
        }
        default:
        {
            throw WrongInputException();
        }
    }
}

void RPN::convert(char *input)
{
    std::string temp_input(input);
    std::stringstream  iss(temp_input);
    std::string         token;

    while (!iss.eof())
    {
        iss >> token;
        if (iss.fail() || iss.bad())
        {
            throw WrongInputException();
        }
        if (isdigit(token[0]))
            _stack.push(std::atol(token.c_str()));
        else
        {
            if (_stack.size() < 2 || token.length() > 1)
                throw WrongInputException();
            double  a = _stack.top();
            _stack.pop();
            double  b = _stack.top();
            _stack.pop();
            _stack.push(calculations(b, a, token[0]));
        }
    }
    if (_stack.size() != 1)
    {
        throw WrongInputException();
    }
    if (_stack.top() > (double)INT_MAX || _stack.top() < (double)INT_MIN)
    {
        throw WrongInputException();
    }
    std::cout << _stack.top() << std::endl;
}

const char* RPN::WrongInputException::what() const throw()
{
    return ("The program does not support that input");
}
