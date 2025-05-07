#include "Dog.hpp"

Dog::Dog(){
	std::cout << ORANGE << "Dog Default constructor" << RESET << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog& copy){
	std::cout << ORANGE << "Dog Copy constructor" << RESET << std::endl;
	this->_type = copy._type;
	this->_brain = new Brain(*copy._brain);
}

Dog& Dog::operator=(const Dog& copy){
	if (this != &copy){
		std::cout << ORANGE << "Dog Copy assignment operator" << RESET << std::endl;
		this->_type = copy.getType();
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*copy._brain);
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

void	Dog::setBrainIdea(std::string newIdea) {
	this->_brain->setIdea(newIdea);
}

std::string* Dog::getBrainIdeas() {
	return this->_brain->getIdeas();
}

void	Dog::displayBrainIdeas() {
	this->_brain->displayIdeas();
}