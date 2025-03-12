/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:48:41 by ismirand          #+#    #+#             */
/*   Updated: 2025/03/12 16:24:47 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact(){
	this->_FirstName = "";
	this->_LastName = "";
	this->_Nickname = "";
	this->_PhoneNumber = "";
	this->_DarkestSecret = "";
}

Contact::~Contact(){
}

void Contact::setFirstName(){
	
	std::string Input = "";
	while (42){
		std::cout << CYAN << "Add First Name: " << RESET;
		std::getline(std::cin, Input);
		if (std::cin.eof()){
			std::cout << std::endl << CTRLD << std::endl;
			std::exit(0); 
		}
		if (!Input.empty() && !has_digit(Input)){
			this->_FirstName = Input;
			break;
		}
		std::cout << RED << "🚨 Please insert a valid First Name" << RESET << std::endl;
	}
}

void Contact::setLastName(){
	
	std::string Input = "";
	while (42){
		std::cout << CYAN << "Add Last Name: " << RESET;
		std::getline(std::cin, Input);
		if (std::cin.eof()){
			std::cout << std::endl << CTRLD << std::endl;
			std::exit(0); 
		}
		if (!Input.empty() && !has_digit(Input)){
			this->_LastName = Input;
			break;
		}
		std::cout << RED << "🚨 Please insert a valid Last Name" << RESET << std::endl;
	}
}

void Contact::setNickname(){
	
	std::string Input = "";
	while (42){
		std::cout << CYAN << "Add Nickname: " << RESET;
		std::getline(std::cin, Input);
		if (std::cin.eof()){
			std::cout << std::endl << CTRLD << std::endl;
			std::exit(0);
		}
		if (!Input.empty()){
			this->_Nickname = Input;
			break;
		}
		std::cout << RED << "🚨 Please insert a valid Nickname" << RESET << std::endl;
	}
}

void Contact::setPhoneNumber(){
	
	std::string Input = "";
	while (42){
		std::cout << CYAN << "Add PhoneNumber: " << RESET;
		std::getline(std::cin, Input);
		if (std::cin.eof()){
			std::cout << std::endl << CTRLD << std::endl;
			std::exit(0);
		}
		if (!Input.empty() && !has_letter(Input)){
			this->_PhoneNumber = Input;
			break;
		}
		std::cout << RED << "🚨 Please insert a valid PhoneNumber" << RESET << std::endl;
	}
}

void Contact::setDarkestSecret(){
	
	std::string Input = "";
	while (42){
		std::cout << CYAN << "Add DarkestSecret: " << RESET;
		std::getline(std::cin, Input);
		if (std::cin.eof()){
			std::cout << std::endl << CTRLD << std::endl;
			std::exit(0);
		}
		if (!Input.empty()){
			this->_DarkestSecret = Input;
			break;
		}
		std::cout << RED << "🚨 Please insert the Darkest Secret" << RESET << std::endl;
	}
}

std::string Contact::getFirstName(){
	return (this->_FirstName);
}

std::string Contact::getLastName(){
	return (this->_LastName);
}

std::string Contact::getNickname(){
	return (this->_Nickname);
}

std::string Contact::getPhoneNumber(){
	return (this->_PhoneNumber);
}

std::string Contact::getDarkestSecret(){
	return (this->_DarkestSecret);
}