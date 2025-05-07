#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal") {
	std::cout << CYAN << "AAnimal Default constructor" << RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal& copy){
	std::cout << CYAN << "AAnimal Copy constructor" << RESET << std::endl;
	this->_type = copy._type;
}

AAnimal& AAnimal::operator=(const AAnimal& copy){
	if (this != &copy){
		std::cout << CYAN << "AAnimal Copy assignment operator" << RESET << std::endl;
		this->_type = copy.getType();
	}
	return *this;
}

AAnimal::~AAnimal(){
	std::cout << CYAN << "AAnimal destructor" << RESET << std::endl;
}

//----------------------------------------------------------------------------

std::string AAnimal::getType()const{
	return this->_type;
}

/* void AAnimal::makeSound()const{
	std::cout << CYAN BLINK << "AAAAAAAHHHHHH... 🗣️" << RESET << std::endl;
} */