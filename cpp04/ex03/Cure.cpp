#include "Cure.hpp"

Cure::Cure() : AMateria() {
	this->_type = "cure";
}

Cure::Cure(const Cure& src) : AMateria(src) {
}

Cure& Cure::operator=(const Cure& src){
	(void)src;
	return *this;
}

Cure::~Cure(){}

AMateria* Cure::clone() const {
	return (new Cure());
}

void Cure::use(ICharacter &target) {
	std::cout << MGT BLINK "* heals " << target.getName() << "'s wounds *" RESET << std::endl;
}