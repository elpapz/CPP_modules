#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>

int	main(int ac, char ** av)
{
	if (ac != 4)
	{
		std::cout << "Your input is wrong!!" << std::endl;
		exit (EXIT_FAILURE);
	}
	std::string str = av[2];
	if (str.empty())
	{
		std::cout << "Empty string, please put in a valid one!!" << std::endl;
		exit(EXIT_FAILURE);
	}
	std:: string Filename = av[1];
	std:: string strFind = av[2];
	std::string strReplace = av[3];
	Filename.append(".replace");
	std::ifstream sourceFile(av[1]);
	std::ofstream replaceFile(Filename);
	if (!(sourceFile.is_open() || !replaceFile.is_open()))
	{
		std:: cout << "Error opening the files" << std::endl;
		exit (EXIT_FAILURE);
	}
	std::string line;
	while (std::getline(sourceFile, line))
	{
		replaceChar(line, strFind, strReplace);
		replaceFile << line << std::endl;
	}
}

void	replaceChar(std:: string line, std::string Find, std::string Reaplace)
{

}

