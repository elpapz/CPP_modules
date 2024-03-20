#include "RPN.hpp"

RPN::RPN(){}

RPN::~RPN(){}

RPN::RPN(const RPN& copy)
{
	*this = copy;
}

RPN::&RPN::operator=(RPN const& copy)
{
	if (this != &copy)
		return (copy);
	return (*this);
}

static double applyOperation(double a, double b, eOperation op)
{
    switch (op)
    {
        case ADD:
        {
            return (a + b);
        }
        case SUBTRACT:
        {
            return (a - b);
        }
        case MULTIPLY:
        {
            return (a * b);
        }
        case DIVIDE:
        {
            return (a / b);
        }
        default:
        {
            throw InvalidInputException();
        }
    }
}

void RPN::calculate(std::string const& input)
{
    std::istringstream  iss(input);
    std::string         token;

    while (!iss.eof())
    {
        iss >> token;
        if (iss.fail() || iss.bad() || token.length() != 1)
        {
            throw InvalidInputException();
        }
        if (isdigit(token[0]))
        {
            _stack.push(std::atoi(token.c_str()));
        }
        else
        {
            if (_stack.size() < 2)
            {
                throw InvalidInputException();
            }
            double  a = _stack.top();
            _stack.pop();
            double  b = _stack.top();
            _stack.pop();
            _stack.push(applyOperation(b, a, static_cast<eOperation>(token[0])));
        }
    }
    if (_stack.size() != 1)
    {
        throw std::out_of_range("hello");
    }
    std::cout << _stack.top() << std::endl;
}

// const char* InvalidInputException::what() const throw()
// {
//     return ("Error");
// }