#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int deposit)
{
    _displayTimestamp();
    _amount = deposit;
    _totalAmount += deposit;
    _nbAccounts += 1;
    _accountIndex = _nbAccounts;
    std::cout << " index:" << _accountIndex << ';';
    std::cout << "amount:" << _amount << ';' << "created" << std::endl;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ';';
    std::cout << "amount:" << _amount << ';' << "closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal)
{
    if (_amount < withdrawal)
        return false;
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    return true;
}

int Account::checkAmount() const
{
    return (_amount);
}

void Account::_displayTimestamp()
{
    std::time_t localtime = std::time(nullptr);
    std::tm *timeInfo = std::localtime(&localtime);
    std::cout << "[" << (timeInfo->tm_year + 1900) \
                << timeInfo->tm_mon \
                << timeInfo->tm_mday \
                << "_" \
                << timeInfo->tm_hour\
                << timeInfo->tm_min \
                << timeInfo->tm_sec \
                << "]";

}
void Account::displayStatus() const
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";"\
            << "amount:" << _amount << ";"\
            << "deposits:" << _nbDeposits <<  ";"\
            << "withdrawals:" << _nbWithdrawals
            << std::endl;
}

void Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << " accounts:" << _nbAccounts\
                << ";total:" << _totalAmount\
                << ";deposits:" << _totalNbDeposits\
                << ";withdrawals:" << _totalNbWithdrawals\
                << std::endl;
}

int Account::getNbAccounts()
{
    return (_nbAccounts);
}

int Account::getTotalAmount()
{
    return (_totalAmount);
}

int Account::getNbDeposits()
{
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
    return (_totalNbWithdrawals);
}