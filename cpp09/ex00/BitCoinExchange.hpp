#ifndef BIT_COIN_EXCHANGE_HPP
#define BIT_COIN_EXCHANGE_HPP

# include <string>
# include <map>
# include <iostream>
# include <fstream>
# include <string>
# include <sstream>
# include <exception>

class BitCoinExchange
{
	public:
        BitCoinExchange(void);
        BitCoinExchange(const BitCoinExchange& to_copy);
        BitCoinExchange& operator=(const BitCoinExchange& to_copy);
        ~BitCoinExchange(void);
		void 	collect_data(std::ifstream& sourcefile);
		void	read_files(std::string source, std::string input);
		void 	parse_input(std::ifstream& inputfile);
	private:
		std::map<std::string, float> dataBase;
};


#endif
