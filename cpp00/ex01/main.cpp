/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:38:51 by ismirand          #+#    #+#             */
/*   Updated: 2025/02/15 15:44:02 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

bool handle_input(std::string user_input, PhoneBook *phonebook)
{
	if (user_input == "ADD" || user_input == "1")
		phonebook->add();
	else if (user_input == "SEARCH" || user_input == "2")
		phonebook->search();
	else if (user_input == "EXIT" || user_input == "3")
		return false;
	else
		std::cout << "\033[31m" << "Invalid command: Try again\n\n" << "\033[0m";
	return true;
}

int	main(void){
	PhoneBook	phonebook;
	std::string	input;

	while (!std::cin.eof())
	{
		input = "";
		std::cout << "Enter one of These Commands:\n\n1. ADD\n2. SEARCH\n3. EXIT" << std::endl << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "CTRL-D Pressed. Exiting Phonebook!" << std::endl;
			std::exit(0);
		}
		if (!handle_input(input, &phonebook))
			break ;
	}
}
