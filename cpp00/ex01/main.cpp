/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:38:51 by ismirand          #+#    #+#             */
/*   Updated: 2025/03/12 14:11:58 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

bool handle_input(std::string input, PhoneBook *phonebook){
	if (input == "ADD" || input == "add" || input == "1")
		phonebook->add();
	else if (input == "SEARCH" || input == "search" || input == "2")
		phonebook->search();
	else if (input == "EXIT" || input == "exit" || input == "3")
		return (false);
	else
		std::wcout << RED << "Invalid command!" << RESET << std::endl;
	return (true);
}

int	main(void){
	PhoneBook	phonebook;
	std::string	input;
	while (!std::cin.eof()){
		input = "";
		std::wcout << MGT << "Enter one of These Commands:\n1. ADD\n2. SEARCH\n3. EXIT" << RESET << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof()){
			std::wcout << std::endl << CTRLD << std::endl;
			std::exit(0);
		}
		if (!handle_input(input, &phonebook))
			break ;
	}
}
