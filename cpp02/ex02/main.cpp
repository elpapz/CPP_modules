#include "Fixed.hpp"
#include <iostream>

int main()
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}

/*
int	main(void)
{
	titleHeader("SUBJECT TEST");
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a,b) << std::endl;
	pressEnter();

    Fixed c(3.14f);
    Fixed d(c);

	titleHeader("ARITHMETIC OPERATORS");
    Fixed sum = b + c;
    Fixed diff = b - c;
    Fixed prod = b * c;
    Fixed div = b / c;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl << std::endl;

	std::cout << b << " + " << c << ": " << sum << std::endl;
	std::cout << b << " - " << c << ": " << diff << std::endl;
	std::cout << b << " * " << c << ": " << prod << std::endl;
	std::cout << b << " / " << c << ": " << div << std::endl;
	pressEnter();

	titleHeader("COMPARISON OPERATORS");
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl << std::endl;
    bool greater = b > c;
    bool less = b < c;
    bool greaterOrEqual = b >= c;
    bool lessOrEqual = b <= c;
    bool equal = b == c;
    bool notEqual = b != c;
	std::cout << b << " > " << c << ": " << greater << std::endl;
	std::cout << b << " < " << c << ": " << less << std::endl;
	std::cout << b << " >= " << c << ": " << greaterOrEqual << std::endl;
	std::cout << b << " <= " << c << ": " << lessOrEqual << std::endl;
	std::cout << b << " == " << c << ": " << equal << std::endl;
	std::cout << b << " != " << c << ": " << notEqual << std::endl;
	pressEnter();

	titleHeader("INCREMENT OPERATORS");
    Fixed e = a;
    Fixed f = c;
	std::cout << "e = " << e << std::endl;
	std::cout << "f = " << f << std::endl << std::endl;
	std::cout << "e++ = " << e++ << std::endl;
	std::cout << "now e = " << e << std::endl;
	std::cout << "++e = " << ++e << std::endl;
	std::cout << "now e = " << e << std::endl;
	std::cout << std::endl;
	std::cout << "f-- = " << f-- << std::endl;
	std::cout << "now f = " << f << std::endl;
	std::cout << "--f = " << --f << std::endl;
	std::cout << "now f = " << f << std::endl;
	pressEnter();

	titleHeader("MIN AND MAX");
    Fixed minResult = Fixed::min(a, b);
    Fixed maxResult = Fixed::max(a, b);

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl << std::endl;
	std::cout << "Min between " << a << " and " << b << " is " << minResult << std::endl;
	std::cout << "Max between " << a << " and " << b << " is " << maxResult << std::endl;
	pressEnter();

    return 0;
}
*/
