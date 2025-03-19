#include "Harl.hpp"

Harl::Harl(){
}

Harl::~Harl(){
}

void Harl::debug(){
	std::cout << GREEN << "Debug function called" << RESET << std::endl;
}

void Harl::info(){
	std::cout << YELLOW << "Info function called" << RESET << std::endl;
}

void Harl::warning(){
	std::cout << ORANGE << "Warning function called" << RESET << std::endl;
}

void Harl::error(){
	std::cout << RED << "Error function called" << RESET << std::endl;
}

void Harl::complain(std::string level){
	void (Harl::*execute[])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	std::string levels[] = {"debug", "info", "warning", "error"};
	for (int i = 0; i < 4; i++){
		if (level == levels[i]){
			(this->*execute[i])();
			return;
		}
	}
}

/* 
Pointer to member functions
Is a way to store the address of a class method and call it dynamically
Allows to call different functions without knowing their names at compile time
They need to be called on an instance (object) of a class
STORE MULTIPLE FUNCTIONS IN AN ARRAY AND CALL THEM DINAMICALLY
 */