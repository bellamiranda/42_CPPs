#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	_totalAmount += this->_amount;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex <<
	";amount:" << _amount << ";created" << std::endl;
	_nbAccounts += 1;
}

Account::~Account ()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex <<
	";amount:" << _amount << ";closed" << std::endl;
}

void Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts <<
	";total:" << _totalAmount << ";deposits:" <<
	_totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::_displayTimestamp( void )
{
	time_t timestamp = std::time(NULL);
	struct tm time = *std::localtime(&timestamp);

	std::cout << "[" << time.tm_year + 1900 <<
	std::setfill('0') << std::setw(2) << time.tm_mon + 1 <<
	std::setfill('0') << std::setw(2) << time.tm_mday << "_" <<
	std::setfill('0') << std::setw(2) << time.tm_hour <<
	std::setfill('0') << std::setw(2) << time.tm_min <<
	std::setfill('0') << std::setw(2) << time.tm_sec << "] ";
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	_amount += deposit;
	_nbDeposits += 1;
	std::cout << "index:" << _accountIndex << ";p_amount:" <<
	_amount - deposit << "deposit:" << deposit << ";amount:" <<
	_amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex <<
	";p_amount:" << _amount << ";withdrawal:";
	if (withdrawal > _amount)
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_nbWithdrawals += 1;
	std::cout << withdrawal << ";amount:" << _amount <<
	";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true ;
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" <<
	_amount << ";deposits:" << _nbDeposits << ";withdrawal:" <<
	_nbWithdrawals << std::endl;
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}