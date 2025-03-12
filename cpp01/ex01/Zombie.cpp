#include "Zombie.hpp"

Zombie::Zombie(){
	std::cout << MGT << "zombie created!" << RESET << std::endl;
}

Zombie::~Zombie(){
	std::cout << RED << "zombie " << this->name << " destroyed!" << RESET << std::endl;
}

void Zombie::announce(){
	std::cout << CYAN << this->name << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}

void Zombie::setName(std::string name){
	this->name = name;
}