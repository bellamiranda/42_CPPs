#include "Cat.hpp"

Cat::Cat(){
	std::cout << MGT << "Cat Default constructor" << RESET << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(const Cat& copy){
	std::cout << MGT << "Cat Copy constructor" << RESET << std::endl;
	*this = copy;
}

Cat& Cat::operator=(const Cat& copy){
	if (this != &copy){
		std::cout << MGT << "Cat Copy assignment operator" << RESET << std::endl;
		this->_type = copy.getType();
	}
	return *this;
}

Cat::~Cat(){
	std::cout << MGT << "Cat destructor" << RESET << std::endl;
	delete this->_brain;
}

void Cat::makeSound()const{
	std::cout << MGT BLINK << "Miaaauuu... 😸" << RESET << std::endl;
}