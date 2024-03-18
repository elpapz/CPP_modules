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
