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
		line.replace(i, Find.length(), Replace);
		i += Find.length();
	}
}

int	main(int ac, char **av)
{
	2
}