#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <cmath>
#include <sstream>
#include <cstdlib>
#include <exception>

class RPN
{
	private:
		std::stack<int> _stack;
	public:
		RPN();
		~RPN();
		RPN(const RPN& copy);
		RPN &operator=(RPN const& copy);
};

#endif