#include "../includes/PhoneBook.hpp"

Contact::Contact()
{
	this->first_name = "";
	this->last_name = "";
	this->nickname = "";
	this->darkest_secret = "";
	this->number = "";
}

Contact::~Contact(){}


void Contact::set_first_name()
{
	std::string user_input = "";

	while (1)
	{
		std::cout << "First name: ";
		std::getline(std::cin, user_input);
		if (std::cin.eof())
		{
			std::cout << std::endl << "CTRL-D Pressed. Exiting Phonebook!" << std::endl;
			std::exit(0);
		}
		if (!user_input.empty() && !has_digit(user_input))
		{
			this->first_name = user_input;
			break;
		}
		std::cout << "\033[31m" << "Please enter a valid First Name." << "\033[0m" << std::endl;
	}
}

void Contact::set_last_name()
{
	std::string user_input = "";

	while (1)
	{
		std::cout << "Last name: ";
		std::getline(std::cin, user_input);
		if (std::cin.eof())
		{
			std::cout << std::endl << "CTRL-D Pressed. Exiting Phonebook!" << std::endl;
			std::exit(0);
		}
		if (!user_input.empty() && !has_digit(user_input))
		{
			this->last_name = user_input;
			break;
		}
		std::cout << "\033[31m" << "Please enter a valid Last Name." << "\033[0m" << std::endl;
	}
}

void Contact::set_nickname()
{
	std::string user_input = "";

	while (1)
	{
		std::cout << "Nickname: ";
		std::getline(std::cin, user_input);
		if (std::cin.eof())
		{
			std::cout << std::endl << "CTRL-D Pressed. Exiting Phonebook!" << std::endl;
			std::exit(0);
		}
		if (!user_input.empty())
		{
			this->nickname = user_input;
			break ;
		}
		std::cout << "\033[31m" << "Please enter a valid Nickname." << "\033[0m" << std::endl;
	}
}

void Contact::set_darkest_secret()
{
	std::string user_input = "";

	while (1)
	{
		std::cout << "Darkest Secret: ";
		std::getline(std::cin, user_input);
		if (std::cin.eof())
		{
			std::cout << std::endl << "CTRL-D Pressed. Exiting Phonebook!" << std::endl;
			std::exit(0);
		}
		if (!user_input.empty())
		{
			this->darkest_secret = user_input;
			break;
		}
		std::cout << "\033[31m" << "Please enter a valid Darkest Secret." << "\033[0m" << std::endl;
	}
}

void Contact::set_number()
{
	std::string user_input = "\0";

	while (1)
	{
		std::cout << "Phone number: ";
		std::getline(std::cin, user_input);
		if (std::cin.eof())
		{
			std::cout << std::endl << "CTRL-D Pressed. Exiting Phonebook!" << std::endl;
			std::exit(0);
		}
		if (!user_input.empty() && !has_letter(user_input))
		{
			this->number = user_input;
			break;
		}
		std::cout << "\033[31m" << "Please enter a valid phone number." << "\033[0m" << std::endl;
	}
}

std::string Contact::get_first_name()
{
	return (this->first_name);
}

std::string Contact::get_last_name()
{
	return (this->last_name);
}

std::string Contact::get_nickname()
{
	return (this->nickname);
}

std::string Contact::get_darkest_secret()
{
	return (this->darkest_secret);
}

std::string Contact::get_number()
{
	return (this->number);
}
