#include "FragTrap.hpp"

int main(void){
	FragTrap ft("FragTrap");
	ClapTrap ct("ClapTrap");
	ft.attack("ClapTrap");
	ct.takeDamage(30);
	ct.beRepaired(10);
	ft.displayHealth();
	ct.displayHealth();

	ft.highFivesGuys();
	return 0;
}

/* 
VIRTUAL FUNCTION
is a function that can be overridden in a derived class, and when called
through a pointer or reference to the base class, it will execute the
derived class's version, not the base class one
this allows DYNAMIC DISPATCH (explain RUNTIME POLYMORPHISM)
*/