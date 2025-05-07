#include "Cat.hpp"

Cat::Cat(){
	std::cout << MGT << "Cat Default constructor" << RESET << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(const Cat& copy){
	std::cout << MGT << "Cat Copy constructor" << RESET << std::endl;
	this->_type = copy._type;
	this->_brain = new Brain();
	this->_brain->copyIdeas(*copy._brain);
}

Cat& Cat::operator=(const Cat& copy){
	if (this != &copy){
		std::cout << MGT << "Cat Copy assignment operator" << RESET << std::endl;
		this->_type = copy.getType();
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*copy._brain);//use Brain copy constructor - deep copy
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

void	Cat::setBrainIdea(std::string newIdea) {
	this->_brain->setIdea(newIdea);
}

std::string* Cat::getBrainIdeas() {
	return this->_brain->getIdeas();
}

void	Cat::displayBrainIdeas() {
	this->_brain->displayIdeas();
}
