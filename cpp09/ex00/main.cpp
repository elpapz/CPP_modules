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
	int year, month, day, i;
	std::string temp_date;
	std::stringstream ss(date);
	if (date.find_first_of('-') != 4 || date.length() != 10)
	{
		std::cout << "fuck" << std::endl;
		return (false);
	}
	while (std::getline(ss, temp_date, '-'))
	{
		if (i == 0)
		{
			year = ft_stoi(temp_date);
			//std::cout << year << std::endl;
			if (year < 2009 || year > 2022)
				return false;
		}
		if (i == 1)
		{
			month = ft_stoi(temp_date);
			//std::cout << month << std::endl;
			if (month < 1 || month > 12)
				return false;
		}
		
		if (i == 2)
		{
			day = ft_stoi(temp_date);
			//std::cout << day << std::endl;
			if ((day < 1 || day > 31)
			||  (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11)))
				return false;
		}
		
		i += 1;
	}
    if (month == 2)
    {
        if (!isLeapYear(year) && day > 28)
        {
            return (false);
        }
		else
		{
			if (day > 29)
				return (false);
		}
    }
	return (true);
}

bool valid_rate(std::string& rate)
{
	int dot = 0;
	if (rate.empty() || rate.length() < 1)
		return false;
	if (rate[0] == '-')
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return (true);
	}
	else if (rate > "2147483647")
	{
		std::cerr << "Error: too large number." << std::endl;
		return true;
	}
	for (size_t i = 0; i < rate.length(); i++)
	{
		if (rate[i] == '.')
		{
			dot++;
			continue;
		}
		if (!isdigit(rate[i]) || dot > 1)
			return false;
	}
	return true;
}



void BitCoinExchange::parse_input(std::ifstream& inputfile)
{
	float rate;
	std::string rate_raw;
	std::string date;
	std::string line;
	std::stringstream ss;

	std::getline(inputfile, line);
	while (std::getline(inputfile, line))
	{
		int separator = line.find('|');
		if ((unsigned long)separator == std::string::npos
		||	line.length() < (unsigned long)separator + 2)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		date = line.substr(0, separator - 1);
		//std::cout << "date: " << date << std::endl;
		if (valid_date(date) == false)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		rate_raw = line.substr(separator + 2);
		//std::cout << "rate: " << date << std::endl;
		if (valid_rate(rate_raw) == false)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
	
		rate = ft_stof(rate_raw);
		for (std::map<std::string, float>::iterator it = this->_rates.begin(); it != this->_rates.end(); it++)
		{
			std::map<std::string, float>::iterator itt = dataBase.find
			int find = it->first.find(date.c_str());
			if (find == 0)
			{
				if (rate * it->second > 2147483648)
				{
					std::cerr << "Error: too large number." << line << std::endl;
					break ;
				}
				else
				{
					std::cout << date << " => " << rate << " = " << rate * it->second << std::endl;
					break ;
				}
			}
			else
			{
				if (it != this->_rates.begin())
					it--;
				if (rate * it->second > 2147483648)
				{
					std::cerr << "Error: too large number." << line << std::endl;
					break;
				}
				std::cout << date << " => " << rate << " = " << rate * it->second << std::endl;
				return ;
			}
		}
		//std::cout << date << " => " << rate << " = " << rate * getRate(rate_raw) << std::endl;
	}
}

void	BitCoinExchange::read_files(std::string source, std::string input)
{
	std::ifstream inputfile(input.c_str());
	std::ifstream sourcefile(source.c_str());
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
		return (0);
	}
	try
	{
		BitCoinExchange btc;
		btc.read_files("data.csv", av[1]);

	}
	catch(std::exception &e)
	{
		std::cout << "Fucked up shit bruuuuv\n";
	}
}