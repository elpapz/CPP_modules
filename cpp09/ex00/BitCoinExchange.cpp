#include "BitCoinExchange.hpp"

BitCoinExchange::BitCoinExchange(void) {}

BitCoinExchange::BitCoinExchange(const BitCoinExchange& to_copy) {
    *this = to_copy;
}

BitCoinExchange& BitCoinExchange::operator=(const BitCoinExchange& to_copy) {
    this->dataBase = to_copy.dataBase;
    return *this;
}

BitCoinExchange::~BitCoinExchange(void) {}

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

static int ft_stoi(const std::string& str)
{
    int num;
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

static bool valid_date(std::string date)
{
	int year, month, day;
	std::string temp_date;
	std::stringstream ss(date);
	int i = 0;
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
			if (year < 2009 || year > 2022)
				return false;
		}
		if (i == 1)
		{
			month = ft_stoi(temp_date);
			if (month < 1 || month > 12)
				return false;
		}
		
		if (i == 2)
		{
			day = ft_stoi(temp_date);
			if ((day < 1 || day > 31)
			||  (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11)))
				return false;
		}
		
		i += 1;
	}
    if (month == 2)
    {
        if (!isLeapYear(year))
        {
			if (day > 28)
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

static bool valid_rate(std::string& rate, std::string& date)
{
	int dot = 0;
	if (rate.empty() || rate.length() < 1)
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return false;
	}
	if (rate[0] == '-')
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return (false);
	}
	long temp_rate = std::atol(rate.c_str()); 
	if (temp_rate > 2147483647)
	{
		std::cerr << "Error: too large number." << std::endl;
		return false;
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
		if (valid_date(date) == false)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		rate_raw = line.substr(separator + 2);
		if (valid_rate(rate_raw, line) == false)
		{
			continue;
		}
	
		rate = std::atof(rate_raw.c_str());
		std::map<std::string, float>::iterator it_find = dataBase.find(date);
		if (it_find != dataBase.end())
		{
			if (rate * it_find->second > 2147483648)
			{
				std::cerr << "Error: too large number." << line << std::endl;
				continue;
			}
			else
			{
				std::cout << date << " => " << rate << " = " << rate * it_find->second << std::endl;
				continue;
			}
		}
		else
		{	it_find = dataBase.lower_bound(date);
			if (it_find != dataBase.begin())
				--it_find;
			if (rate * it_find->second > 2147483648)
			{
				std::cerr << "Error: too large number." << line << std::endl;
				continue;
			}
			std::cout << date << " => " << rate << " = " << rate * it_find->second << std::endl;
			continue;
		}
		
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
