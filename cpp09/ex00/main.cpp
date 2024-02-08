#include "BitCoinExchange.hpp"


static bool isLeapYear(int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            return (year % 400 == 0);
        }
        return (true);
    }
    return (false);
}

int ft_stoi(const std::string& str)
{
    int num;
    std::stringstream ss(str);

    ss >> num;
    return num;
}

float ft_stof(const std::string& str)
{
    float num;
    std::stringstream ss(str);

    ss >> num;
    return num;
}

void BitCoinExchange::collect_data(std::ifstream& sourcefile)
{
	 std::string line;
    size_t i;
	float result;

    std::getline(sourcefile, line);
    while (std::getline(sourcefile, line))
    {
        i = line.find(',');
        std::string rate = line.substr(i + 1);
		std::stringstream ss(rate);
		ss >> result;
        this->dataBase[line.substr(0, i)] = result;
    }
    sourcefile.close();
}

bool valid_date(std::string date)
{

}

bool valid_rate(std::string date)
{

}

void	parse_input(std::ifstream& inputfile)
{
	int day;
	int month;
	int year;
	std::string line;
	std::stringstream ss;
	int i = 0;
	while (std::getline(inputfile, line))
	{
		int separator = line.find('|');
		if (separator == std::string::npos
		||	line.length() < separator + 2)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue; 
		}
		std::string date = line.substr(0, separator - 1);
		if (valid_date(date) == false)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		date = line.substr(separator + 2);
		else if (valid_rate(date) == false)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
	}
}

void	BitCoinExchange::read_files(std::string source, std::string input)
{
	std::ifstream inputfile(input);
	std::ifstream sourcefile(source);
	if (!inputfile.is_open() || !sourcefile.is_open())
		throw std::runtime_error("Trouble opening the files\n");
	collect_data(sourcefile);
	parse_input(inputfile);
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Wrong number of arguments\n";
		exit(EXIT_FAILURE);
	}
	try
	{
		BitCoinExchange btc;
		btc.read_files("data.csv", av[1]);

	}
}