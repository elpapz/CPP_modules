#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP
#include <iostream>

#define CHAR	1
#define INT		2
#define FLOAT	3
#define DOUBLE	4
#define LITERALS 5
#define ERROR	0


class ScalarConverter
{
	public:
		static void convert(std::string input);
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
		ScalarConverter& operator=(const ScalarConverter& copy);
};

#endif
