#include "FragTrap.hpp"

FragTrap::FragTrap() {
	std::cout << "FragTrap constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name){
	std::cout << "FragTrap Name constructor called for " << name << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& copy){
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = copy;
}

FragTrap& FragTrap::operator=(const FragTrap& copy){
	if (this != &copy){
		std::cout << "FragTrap Copy assignment operator called" << std::endl;
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	return *this;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap destructor called for " << this->_name << std::endl;
}

//----------------------------------------------------------------------------

void FragTrap::attack(const std::string& target){
	if (target.empty()){
		std::cout << CYAN << "Insert a valid target" << RESET << std::endl;
		return;
	}
	if (this->_hitPoints <= 0){
		std::cout << MGT << "FragTrap " << this->_name << " has no Hit Points and cannot attack" << RESET << std::endl;
		return;
	}
	if (this->_energyPoints <= 0){
		std::cout << MGT << "FragTrap " << this->_name << " has no Energy Points and cannot attack" << RESET << std::endl;
		return;
	}
	else if (this->_hitPoints && this->_energyPoints){
		std::cout << RED << "FragTrap " << this->_name << " attacks " << 
		target << ", causing " << this->_attackDamage << " points of damage!" << 
		RESET << std::endl;
		this->_energyPoints--;
	}
}

void FragTrap::highFivesGuys() {
	std::cout << GREEN << "FragTrap " << this->_name << " asks for a high five 🖐️" << std::endl;
	std::cout << "  ----  HIGH FIVE BUDDY!!  ----  " << RESET << std::endl;
}
