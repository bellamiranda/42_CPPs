/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:48:41 by ismirand          #+#    #+#             */
/*   Updated: 2025/02/24 16:24:05 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact(){
	this->FirstName = "";
	this->LastName = "";
	this->Nickname = "";
	this->PhoneNumber = "";
	this->DarkestSecret = "";
}

Contact::~Contact(){
}

void Contact::set_FirstName(){
	
	std::string Input = "";
	while (42){
		std::cout << CYAN << "Add First Name: " << RESET;
		std::getline(std::cin, Input);
		if (std::cin.eof()){
			std::cout << std::endl << CTRLD << std::endl;
			std::exit(0); 
		}
		if (!Input.empty() && !has_digit(Input)){
			this->FirstName = Input;
			break;
		}
		std::cout << RED << "🚨 Please insert a valid First Name" << RESET << std::endl;
	}
}

void Contact::set_LastName(){
	
	std::string Input = "";
	while (42){
		std::cout << CYAN << "Add Last Name: " << RESET;
		std::getline(std::cin, Input);
		if (std::cin.eof()){
			std::cout << std::endl << CTRLD << std::endl;
			std::exit(0); 
		}
		if (!Input.empty() && !has_digit(Input)){
			this->LastName = Input;
			break;
		}
		std::cout << RED << "🚨 Please insert a valid Last Name" << RESET << std::endl;
	}
}

void Contact::set_Nickname(){
	
	std::string Input = "";
	while (42){
		std::cout << CYAN << "Add Nickname: " << RESET;
		std::getline(std::cin, Input);
		if (std::cin.eof()){
			std::cout << std::endl << CTRLD << std::endl;
			std::exit(0);
		}
		if (!Input.empty()){
			this->Nickname = Input;
			break;
		}
		std::cout << RED << "🚨 Please insert a valid Nickname" << RESET << std::endl;
	}
}

void Contact::set_PhoneNumber(){
	
	std::string Input = "";
	while (42){
		std::cout << CYAN << "Add PhoneNumber: " << RESET;
		std::getline(std::cin, Input);
		if (std::cin.eof()){
			std::cout << std::endl << CTRLD << std::endl;
			std::exit(0);
		}
		if (!Input.empty() && !has_letter(Input)){
			this->PhoneNumber = Input;
			break;
		}
		std::cout << RED << "🚨 Please insert a valid PhoneNumber" << RESET << std::endl;
	}
}

void Contact::set_DarkestSecret(){
	
	std::string Input = "";
	while (42){
		std::cout << CYAN << "Add DarkestSecret: " << RESET;
		std::getline(std::cin, Input);
		if (std::cin.eof()){
			std::cout << std::endl << CTRLD << std::endl;
			std::exit(0);
		}
		if (!Input.empty()){
			this->DarkestSecret = Input;
			break;
		}
		std::cout << RED << "🚨 Please insert the Darkest Secret" << RESET << std::endl;
	}
}

std::string Contact::get_FirstName(){
	return (this->FirstName);
}

std::string Contact::get_LastName(){
	return (this->LastName);
}

std::string Contact::get_Nickname(){
	return (this->Nickname);
}

std::string Contact::get_PhoneNumber(){
	return (this->PhoneNumber);
}

std::string Contact::get_DarkestSecret(){
	return (this->DarkestSecret);
}