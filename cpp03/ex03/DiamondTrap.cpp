#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(){
	ScavTrap scav;
	std::cout << "DiamondTrap Constructor called" << std::endl;
	ClapTrap::_name = _name + "_clap_name";
	this->_energyPoints = scav.getEnergyPoints();
}

//initialize the ClapTrap part of the diamond with a different name
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), _name(name){
	ScavTrap scav("temp_scav");
	std::cout << "DiamondTrap Name constructor called for " << name << std::endl;
	this->_energyPoints = scav.getEnergyPoints();
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy){
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
	*this = copy;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy){
	ClapTrap clap(copy);
	if (this != &copy){
		std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
		ClapTrap::_name = clap.getName();
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	return *this;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap Destructor called for " << this->_name << std::endl;
}

//----------------------------------------------------------------------------

void DiamondTrap::whoAmI(){
	std::cout << GREEN << "DiamondTrap's name: " << this->_name << 
	"\nClapTrap's name: " << ClapTrap::_name << RESET << std::endl;
}