#include "ClapTrap.hpp"

int main(void){
	ClapTrap maria("Maria");
	ClapTrap joao("Joao");

	maria.setAttackDamage(2);

	maria.attack("Joao");
	joao.takeDamage(2);
	joao.displayHealth();
	maria.displayHealth();

	joao.beRepaired(4);
	joao.displayHealth();

	for (int i = 0; i < 7; i++){
		maria.attack("Joao");
		joao.takeDamage(2);
	}
	maria.displayHealth();
	joao.displayHealth();

	ClapTrap pedro;
	pedro = joao;

	pedro.displayHealth();
	for (int i = 0; i < 3; i++){
		maria.attack("pedro");
		pedro.takeDamage(2);
	}
	maria.displayHealth();
	pedro.displayHealth();
}

/* 
INHERITANCE - create a class based on another class
	reuse and extend its behavior (base class -> derived class)
	It gives access to all public methods and attributes of the class
class B : public A -> public members stay public
class B : protected A -> public becomes protected
	acessible inside the class and subclasses (inherited)
class B : private A -> public becomes private

* Constructors in derived classses must call base class constructors if needed
* Destructors must be virtual in base classes if dealing with polymorphism
* Always test constructors and destructors to see inheritance flow
 */