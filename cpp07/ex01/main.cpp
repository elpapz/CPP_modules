#include "iter.hpp"


int main()
{
	int 		array1[5] = {0, 12, 99, -4, 35};
	char 		array2[4] = {'q', 'w', 'e', 'r'};
	std::string array3[3] = {"my", "name", "is"};

	std::cout << "1st Array - Ints: \n";
	iter(array1, 5, print_str<int>);
	std::cout << std::endl;

	std::cout << "2nd Array - Chars: \n";
	iter(array2, 4, print_str<char>);
	std::cout << std::endl;

	std::cout << "3rd Array - Strings: \n";
	iter(array3, 3, print_str<std::string>);
	std::cout << std::endl;
}

/*
class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  iter( tab, 5, print<const int> );
  iter( tab2, 5, print<Awesome> );

  return 0;
}
*/
