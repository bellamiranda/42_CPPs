#include "Wrong.hpp"

WrongAnimal::WrongAnimal() : _type("Wrong Animal") {
	std::cout << RED << "Wrong Animal Default constructor" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy){
	std::cout << RED << "Wrong Animal Copy constructor" << RESET << std::endl;
	*this = copy;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy){
	if (this != &copy){
		std::cout << RED << "Wrong Animal Copy assignment operator" << RESET << std::endl;
		this->_type = copy.getType();
	}
	return *this;
}

WrongAnimal::~WrongAnimal(){
	std::cout << RED << "Wrong Animal destructor" << RESET << std::endl;
}

//----------------------------------------------------------------------------

std::string WrongAnimal::getType()const{
	return this->_type;
}

void WrongAnimal::makeSound()const{
	std::cout << RED BLINK << "WRONG ANIMAL... 🗣️" << RESET << std::endl;
}

//----------------------------------------------------------------------------

WrongCat::WrongCat(){
	std::cout << RED << "Wrong Cat Default constructor" << RESET << std::endl;
	this->_type = "Wrong Cat";
}

WrongCat::WrongCat(const WrongCat& copy){
	std::cout << RED << "Wrong Cat Copy constructor" << RESET << std::endl;
	*this = copy;
}

WrongCat& WrongCat::operator=(const WrongCat& copy){
	if (this != &copy){
		std::cout << RED << "Wrong Cat Copy assignment operator" << RESET << std::endl;
		this->_type = copy.getType();
	}
	return *this;
}

WrongCat::~WrongCat(){
	std::cout << RED << "Wrong Cat destructor" << RESET << std::endl;
}

//----------------------------------------------------------------------------

void WrongCat::makeSound()const{
	std::cout << RED BLINK << "WRONG CAT... 😸" << RESET << std::endl;
}