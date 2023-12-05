#include <iostream>

int main(void)
{
	std::string str("HI THIS IS BRAIN");
	std::string *stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "String Memory adress: " << &str << std::endl;
	std::cout << "stringPointer Memory Adress: " << &stringPTR << std::endl;
	std::cout << "stringReference Memory Adress" << &stringREF << std::endl;

	std::cout << "String Value: " << str << std::endl;
	std::cout << "stringPointer Value: " << *stringPTR << std::endl;
	std::cout << "stringReference Value" << stringREF << std::endl;
}