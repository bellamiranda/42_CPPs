#include "Ice.hpp"

Ice::Ice() : AMateria() {
	this->_type = "ice";
}

Ice::Ice(const Ice& src) : AMateria(src) {}

Ice& Ice::operator=(const Ice& src){
	(void)src;
	return *this;
}

Ice::~Ice(){}

AMateria* Ice::clone() const {
	return (new Ice());
}

void Ice::use(ICharacter &target) {
	std::cout << CYAN BLINK "* shoots an ice bolt at " << target.getName() << " *" RESET << std::endl;
}