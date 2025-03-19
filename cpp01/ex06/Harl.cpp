#include "Harl.hpp"

Harl::Harl(){
}

Harl::~Harl(){
}

void Harl::debug(){
	std::cout << GREEN << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n" << RESET << std::endl;
}

void Harl::info(){
	std::cout << YELLOW << "[ INFO ]\nI cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << RESET << std::endl;
}

void Harl::warning(){
	std::cout << ORANGE << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI’ve been coming for years, whereas you started working here just last month.\n" << RESET << std::endl;
}

void Harl::error(){
	std::cout << RED << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now." << RESET << std::endl;
}

void Harl::complain(std::string level){
	void (Harl::*execute[])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = -1;
	while (++i < 4)
		if (level == levels[i])
			break;
	switch (i){
		case 0:
			(this->*execute[i++])();
		case 1:
			(this->*execute[i++])();
		case 2:
			(this->*execute[i++])();
		case 3:
			(this->*execute[i])();
			break;
		default:
			std::cout << CYAN << "[ Probably complaining about insignificant problems ]" << RESET << std::endl;
	}
}

/* 
SWITCH STATEMENT
used when you need to compare a variable against multiple constant values
cleaner and more efficient alternative to multiple if-else statements
- only works with int, char or enum

switch (expression){
	case value1:
		execute if expression == value1
		break;
	case value2:
		execute if expression == value2
		break;
	default: [OPTIONAL, LIKE THE ELSE]
		execute if none of the above cases match
} */