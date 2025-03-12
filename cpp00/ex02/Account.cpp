/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:52:35 by ismirand          #+#    #+#             */
/*   Updated: 2025/03/12 14:11:58 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(){
	time_t timestamp = std::time(NULL);
	struct tm time = *std::localtime(&timestamp);
	std::wcout << "[" << time.tm_year + 1900 <<
	std::setfill('0') << std::setw(2) << time.tm_mon + 1 <<
	std::setfill('0') << std::setw(2) << time.tm_mday << "_" <<
	std::setfill('0') << std::setw(2) << time.tm_hour <<
	std::setfill('0') << std::setw(2) << time.tm_min <<
	std::setfill('0') << std::setw(2) << time.tm_sec << "] ";
}

Account::Account(int initial_deposit){
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_totalAmount += this->_amount;
	_displayTimestamp();
	std::wcout << "index:" << _accountIndex <<
	";amount:" << _amount << ";created" << std::endl;
	_nbAccounts++;
}

Account::~Account(){
	_displayTimestamp();
	std::wcout << "index:" << _accountIndex <<
	";amount:" << _amount << ";closed" << std::endl;
}

int	Account::getNbAccounts(){
	return (_nbAccounts);
}

int	Account::getTotalAmount(){
	return (_totalAmount);
}

int	Account::getNbDeposits(){
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(){
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(){
	_displayTimestamp();
	std::wcout << "accounts:" << getNbAccounts() << ";total:" <<
	getTotalAmount() << ";deposits:" << getNbDeposits() <<
	";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit){
	_displayTimestamp();
	std::wcout << "index:" << this->_accountIndex <<
	";p_amount:" << this->_amount << ";deposit:" <<
	deposit << ";amount:";
	this->_amount += deposit;
	std::wcout << this->_amount << ";nb_deposits:" <<
	++this->_nbDeposits << std::endl;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal){
	_displayTimestamp();
	std::wcout << "index:" << this->_accountIndex <<
	";p_amount:" << this->_amount << ";withdrawal:";
	if (withdrawal > this->_amount){
		std::wcout << "refused" << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	std::wcout << withdrawal << ";amount:" << this->_amount <<
	";nb_withdrawals:" << ++this->_nbWithdrawals << std::endl;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	return (true);
}

int Account::checkAmount()const{
	return (_amount);
}

void Account::displayStatus()const{
	_displayTimestamp();
	std::wcout << "index:" << this->_accountIndex <<
	";amount:" << this->_amount << ";deposits:" <<
	this->_nbDeposits << ";withdrawals:" <<
	this->_nbWithdrawals << std::endl;
}