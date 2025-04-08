#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
	std::cout << "Default constructor called" << std::endl;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name){
	std::cout << "Name constructor called" << std::endl;
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& copy){
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy){
	std::cout << "Copy assignment operator" << std::endl;
	if (this != &copy)
		_name = copy.getName();
	return *this;
}

ClapTrap::~ClapTrap(){
	std::cout << "Destructor called" << std::endl;
}

//----------------------------------------------------------------------------

std::string ClapTrap::getName() const {
	return this->_name;
}

int ClapTrap::getHitPoints() const {
	return this->_hitPoints;
}

int ClapTrap::getEnergyPoints() const {
	return this->_energyPoints;
}

int ClapTrap::getAttackDamage() const {
	return this->_energyPoints;
}

void ClapTrap::setAttackDamage(int amount){
	this->_attackDamage = amount;
}

//----------------------------------------------------------------------------

void ClapTrap::attack(const std::string& target){
	if (target.empty()){
		std::cout << CYAN << "Insert a valid target" << RESET << std::endl;
		return;
	}
	if (!this->_hitPoints){
		std::cout << MGT << "ClapTrap " << this->_name << " has no Hit Points and cannot attack" << RESET << std::endl;
		return;
	}
	if (!this->_energyPoints){
		std::cout << MGT << "ClapTrap " << this->_name << " has no Energy Points and cannot attack" << RESET << std::endl;
		return;
	}
	else if (this->_hitPoints && this->_energyPoints){
		std::cout << RED << "ClapTrap " << this->_name << " attacks " << 
		target << ", causing " << this->_attackDamage << " points of damage!" << 
		RESET << std::endl;
		this->_energyPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount){
	if (amount <= 0){
		std::cout << CYAN << "Insert a positive amount for damage" << RESET << std::endl;
		return;
	}
	if (!this->_hitPoints){
		std::cout << MGT << "ClapTrap " << this->_name << " is dead and cannot be attacked" << RESET << std::endl;
		return;
	}
	else if (this->_hitPoints){
		std::cout << ORANGE << "ClapTrap " << this->_name << " got " << 
		amount << " points of damage" << RESET << std::endl;
		this->_hitPoints -= amount;
		if (this->_hitPoints <= 0)
			std::cout << ORANGE << "ClapTrap " << this->_name << " is dead ☠️" << RESET << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount){
	if (amount <= 0){
		std::cout << CYAN << "Insert a positive amount for repairing" << RESET << std::endl;
		return;
	}
	if (!this->_hitPoints){
		std::cout << MGT << "ClapTrap " << this->_name << " has no Hit Points and cannot be repaired" << RESET << std::endl;
		return;
	}
	if (!this->_energyPoints){
		std::cout << MGT << "ClapTrap " << this->_name << " has no Energy Points and cannot be repaired" << RESET << std::endl;
		return;
	}
	else if (this->_hitPoints && this->_energyPoints){
		std::cout << GREEN << "ClapTrap " << this->_name << " was repaired and gained " << 
		amount << " hit points" << RESET << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints--;
	}
}

void ClapTrap::displayHealth(){
	std::cout << CYAN << "ClapTrap " << this->_name << " has a total of:\n" << 
	"Hit points: " << this->_hitPoints << 
	"\nEnergy points: " << this->_energyPoints <<
	"\nAttack damage: " << this->_attackDamage << RESET << std::endl; 
}