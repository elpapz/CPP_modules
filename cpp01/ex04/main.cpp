#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <cstdlib>

void	replaceChar(std::string& line, std::string Find, std::string Replace)
{
	size_t i = 0;
	while (i <= line.length())
	{
		i = line.find(Find, i);
		if (i == std::string::npos)
			break ;
		line.erase(i, Find.length());
		line.insert(i, Replace);
		i += Find.length();
	}
}

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Wrong number of paremeters!!\n";
		exit(EXIT_FAILURE);
	}
	if (!av[2] || !av[3])
	{
		std::cout << "The find and replace strings can't be empty" << std::endl;
	}
	std::string line;
	std::string newFile = av[1];
	std::string Find = av[2];
	std::string Replace = av[3];
	std::ifstream file(av[1]);
	newFile += ".replace";
	std::ofstream replaceFile(newFile.c_str());
	if (!file.is_open() || !replaceFile.is_open())
	{
		std::cout << "Something went wrong while opening the files\n";
		exit(EXIT_FAILURE);
	}
	else
	{
		while(std::getline(file, line))
		{
			replaceChar(line, Find, Replace);
			replaceFile << line << std::endl;
		}
		file.close();
		replaceFile.close();
	}
}
