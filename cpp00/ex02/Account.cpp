/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:52:35 by ismirand          #+#    #+#             */
/*   Updated: 2025/02/26 15:55:18 by ismirand         ###   ########.fr       */
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

Account::Account(int initial_deposit){
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	_totalAmount += this->_amount;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex <<
	";amount:" << _amount << ";created" << std::endl;
	_nbAccounts++;
}

Account::~Account(){
	_displayTimestamp();
	
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
	for (int i; i < 8; i++){
		std::cout << _displayTimestamp;
		std::cout << "index:" << i;
		if (getNbDeposits == 0 && getNbWithdrawals == 0){
			std::cout << ";ammount:" << getTotalAmount;//como vou pegar o valor
			std::cout << ";created" << std::endl;
		}
		else if (getNbDeposits && getNbWithdrawals == 0){
			std::cout << ";p_ammount:" << getTotalAmount;//como?
			std::cout << ";deposit:" << getNbDeposits;//como pegar o valor
			std::cout << ";ammount:" << getTotalAmount;
			std::cout << ";nb_deposit:" << getNbDeposits << std::endl;
		}
		else if (getNbDeposits && getNbWithdrawals){
			std::cout << ";p_ammount:" << getTotalAmount;//como?
			std::cout << ";withdrawals:" << getNbWithdrawals;//como
			std::cout << ";ammount:" << getTotalAmount;
			std::cout << "nb_withdrawals:" << getNbWithdrawals << std::endl;
		}
	}
}

void Account::displayStatus()const{
	
}

void Account::makeDeposit(int deposit){
	
}