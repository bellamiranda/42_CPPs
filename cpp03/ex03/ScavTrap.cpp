#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
	std::cout << "ScavTrap Constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name){
	std::cout << "ScavTrap Name constructor called for " << name << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& copy){
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = copy;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy){
	if (this != &copy){
		std::cout << "ScavTrap Copy assignment operator called" << std::endl;
		this->_name = copy.getName();
		this->_hitPoints = copy.getHitPoints();
		this->_energyPoints = copy.getEnergyPoints();
		this->_attackDamage = copy.getAttackDamage();
	}
	return *this;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap Destructor called for " << this->_name << std::endl;
}

//----------------------------------------------------------------------------

void ScavTrap::attack(const std::string& target){
	if (target.empty()){
		std::cout << CYAN << "Insert a valid target" << RESET << std::endl;
		return;
	}
	if (this->_hitPoints <= 0){
		std::cout << MGT << "ScavTrap " << this->_name << " has no Hit Points and cannot attack" << RESET << std::endl;
		return;
	}
	if (this->_energyPoints <= 0){
		std::cout << MGT << "ScavTrap " << this->_name << " has no Energy Points and cannot attack" << RESET << std::endl;
		return;
	}
	else if (this->_hitPoints && this->_energyPoints){
		std::cout << RED << "ScavTrap " << this->_name << " attacks " << 
		target << ", causing " << this->_attackDamage << " points of damage!" << 
		RESET << std::endl;
		this->_energyPoints--;
	}
}

void ScavTrap::guardGate(){
	std::cout << ORANGE << "ScavTrap " << this->getName() << " is now in Gate keeper mode" << RESET << std::endl;
}
