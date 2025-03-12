/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:53:24 by ismirand          #+#    #+#             */
/*   Updated: 2025/03/12 16:24:47 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
	this->saved = 0;
	this->oldest = 0;
	std::cout << GREEN << "\nWELCOME TO THE CRAPPY AWESOME PHONEBOOK SOFTWARE 8 📞📜\n" << RESET << std::endl;
}

PhoneBook::~PhoneBook(){
	std::cout << RED << "\nThe Phonebook was destructed 💥" << RESET << std::endl << std::endl;
}

void PhoneBook::add(){
	if (saved < 8){
		std::cout << CYAN << "\n----------- ADDING A NEW CONTACT -----------" << RESET << std::endl;
		contacts[saved].setFirstName();
		contacts[saved].setLastName();
		contacts[saved].setNickname();
		contacts[saved].setPhoneNumber();
		contacts[saved].setDarkestSecret();
		std::cout << GREEN << "\nNew contact " << contacts[saved].getFirstName() 
			<< " added to the Phonebook 📩" << RESET << std::endl << std::endl;
		saved++;
		return;
	}
	std::cout << RED << "\nOldest contact " << contacts[oldest].getFirstName() 
	<< " deleted from the Phonebook to free space 🗑️" << RESET << std::endl << std::endl;
	contacts[oldest].setFirstName();
	contacts[oldest].setLastName();
	contacts[oldest].setNickname();
	contacts[oldest].setPhoneNumber();
	contacts[oldest].setDarkestSecret();
	std::cout << GREEN << "\nNew contact " << contacts[oldest].getFirstName() 
	<< " added to the PhoneBook 📩" << RESET << std::endl;
	if (oldest < 7)
		oldest++;
	else
		oldest = 0;
}

void PhoneBook::search(){
	if (saved == 0){
		std::cout << RED << "The PhoneBook is empty, nothing to search. Try adding first...\n" << RESET << std::endl;
		return;
	}
	printPhoneBook();
	if (std::cin.eof()){
		std::cout << std::endl << CTRLD << std::endl;
		std::exit(0);
	}
	printContact();
}

void PhoneBook::printPhoneBook(){
	std::cout << MGT << "----------------- CONTACTS -----------------" << std::endl;
	std::cout << "     INDEX" << "|";
	std::cout << "FIRST NAME" << "|";
	std::cout << " LAST NAME" << "|";
	std::cout << "  NICKNAME" << RESET << std::endl;
	for (int i = 0; i < saved; i++){
		std::cout << MGT << std::setw(10) << i + 1 << "|";
		std::cout << std::setw(10) << truncate(contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << truncate(contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << truncate(contacts[i].getNickname()) << RESET << std::endl;
	}
	std::cout << MGT << "--------------------------------------------" << RESET << std::endl;
}

void PhoneBook::printContact(){
	int			index;
	std::string	str;
	std::cout << CYAN << "🔎 Enter the index of the contact to display: " << RESET;
	std::getline(std::cin, str);
	if (std::cin.eof()){
		std::cout << std::endl << CTRLD << std::endl;
		std::exit(0);
	}
	index = std::atoi(str.c_str());
	while (index <= 0 || index > saved){
		std::cout << CYAN << "🚨 Please enter an existing contact index: " << RESET;
		std::getline(std::cin, str);
		if (std::cin.eof()){
			std::cout << std::endl << CTRLD << std::endl;
			std::exit(0);
		}
		index = std::atoi(str.c_str());
	}
	index--;
    std::cout << std::endl << GREEN << "First Name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << RESET << std::endl << std::endl;
}

bool has_digit(std::string str){
	for (unsigned int i = 0; i < str.length(); i++)
		if (str[i] >= '0' && str[i] <= '9')
			return (true);
	return (false);
}

bool has_letter(std::string str){
	for (unsigned int i = 0; i < str.length(); i++)
		if (str[i] < '0' || str[i] > '9')
			return (true);
	return (false);
}

std::string truncate(std::string str){
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}