#include "ScavTrap.hpp"

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ClapTrap maria("Maria");
	maria.attack("Maria");
	maria.takeDamage(10);
	maria.beRepaired(10);
	maria.displayHealth();
	std::cout << std::endl;	

	ScavTrap bob("Bob");
	ScavTrap copy(bob);
	bob.attack("Copy");
	copy.takeDamage(20);
	std::cout << " --- COPY HEALTH --- " << std::endl;
	copy.displayHealth();
	copy.beRepaired(20);
	std::cout << " --- COPY HEALTH --- " << std::endl;
	copy.displayHealth();
	std::cout << " --- BOB HEALTH --- " << std::endl;
	bob.displayHealth();
	bob.guardGate();
	return 0;
}


/* 
ClapTrap's constructor run first
	then ScavTrap's can add or override behavior
*/