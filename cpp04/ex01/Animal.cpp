#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
	std::cout << CYAN << "Animal Default constructor" << RESET << std::endl;
}

Animal::Animal(const Animal& copy){
	std::cout << CYAN << "Animal Copy constructor" << RESET << std::endl;
	this->_type = copy._type;
}

Animal& Animal::operator=(const Animal& copy){
	if (this != &copy){
		std::cout << CYAN << "Animal Copy assignment operator" << RESET << std::endl;
		this->_type = copy.getType();
	}
	return *this;
}

Animal::~Animal(){
	std::cout << CYAN << "Animal destructor" << RESET << std::endl;
}

//----------------------------------------------------------------------------

std::string Animal::getType()const{
	return this->_type;
}

void Animal::makeSound()const{
	std::cout << CYAN BLINK << "AAAAAAAHHHHHH... 🗣️" << RESET << std::endl;
}