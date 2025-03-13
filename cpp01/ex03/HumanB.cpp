#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name){
	std::cout << GREEN << "Human B " << this->_name <<
	" created without weapon" << RESET << std::endl;
	this->_weapon = NULL;
}

HumanB::~HumanB(){
	std::cout << RED << "Human B " << this->_name <<
	" destructed" << RESET << std::endl;
}

void HumanB::attack(){
	if (this->_weapon == NULL){
		std::cout << MGT << this->_name << " has no weapon to attack" << std::endl;
		return;
	}
	std::cout << CYAN << this->_name << " attacks with their " <<
	this->_weapon->getType() << RESET << std::endl;
}

void HumanB::setWeapon(Weapon &weapon){
	this->_weapon = &weapon;
}