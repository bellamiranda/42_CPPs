#include "Dog.hpp"

Dog::Dog(){
	std::cout << ORANGE << "Dog Default constructor" << RESET << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog& copy){
	std::cout << ORANGE << "Dog Copy constructor" << RESET << std::endl;
	*this = copy;
}

Dog& Dog::operator=(const Dog& copy){
	if (this != &copy){
		std::cout << ORANGE << "Dog Copy assignment operator" << RESET << std::endl;
		this->_type = copy.getType();
	}
	return *this;
}

Dog::~Dog(){
	std::cout << ORANGE << "Dog destructor" << RESET << std::endl;
	delete this->_brain;
}

void Dog::makeSound()const{
	std::cout << ORANGE BLINK << "Auu auuu... 🐶" << RESET << std::endl;
}