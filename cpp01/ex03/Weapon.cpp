#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {
	std::cout << GREEN << "Weapon " << this->_type <<
	" created" << RESET << std::endl;
}

Weapon::~Weapon(){
	std::cout << RED << "Weapon " << this->_type <<
	" destructed" << RESET << std::endl;
}

const std::string& Weapon::getType(){
	return(_type);
}

void Weapon::setType(std::string newValue){
	this->_type = newValue;
}