#include "Zombie.hpp"

Zombie::Zombie(std::string name){
	this->name = name;
}

Zombie::~Zombie(){
	std::wcout << RED << this->name << "destroyed!" << RESET << std::endl;
	//must print a message with the name ofthe zombie for debugging
}

void Zombie::announce(){
	std::wcout << CYAN << this->name << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
	//print -> Name: BraiiiiiiinnnzzzZ...
}
