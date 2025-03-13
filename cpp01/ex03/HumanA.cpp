#include "HumanA.hpp"

//initializer list (initialize variables before the contructor's function do it)
//const and reference members HAVE to be initialized in list (cannot be assigned new values after declaration)
HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon){
	std::cout << GREEN << "HumanA " << this->_name <<
	" created with the weapon " << this->_weapon.getType() << RESET << std::endl;
}

HumanA::~HumanA(){
	std::cout << RED << "HumanA " << this->_name << " destructed" <<std::endl;
}

void HumanA::attack(){
	std::cout << CYAN << this->_name << " attacks with their " <<
	this->_weapon.getType() << RESET << std::endl;
}