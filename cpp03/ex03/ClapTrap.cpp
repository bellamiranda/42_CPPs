#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap Name constructor called for " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy){
	std::cout << "ClapTrap Copy constructor called for " << std::endl;
	*this = copy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy){
	if (this != &copy){
		std::cout << "ClapTrap Copy assignment operator called" << std::endl;
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap Destructor called for " << this->_name << std::endl;
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
	return this->_attackDamage;
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
	if (this->_hitPoints <= 0){
		std::cout << MGT << "ClapTrap " << this->_name << " has no Hit Points and cannot attack" << RESET << std::endl;
		return;
	}
	if (this->_energyPoints <= 0){
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
	if (this->_hitPoints <= 0){
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
	if (this->_hitPoints <= 0){
		std::cout << MGT << "ClapTrap " << this->_name << " has no Hit Points and cannot be repaired" << RESET << std::endl;
		return;
	}
	if (this->_energyPoints <= 0){
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