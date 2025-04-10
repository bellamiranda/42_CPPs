#include "DiamondTrap.hpp"

int main(void){
	DiamondTrap joao("Joao");
	ClapTrap ana("Ana");
	FragTrap pedro("Pedro");
	ScavTrap maria("Maria");
	ana.displayHealth();//10, 10, 0
	pedro.displayHealth();//100, 100, 30
	maria.displayHealth();//100, 50, 20

	joao.displayHealth();//hp = 100 (scav) / ep = 50 (scav) / ad = 30 (frag)
	joao.attack("Maria");//ScavTrap

	joao.whoAmI();
	DiamondTrap daniel("Daniel");
	daniel.whoAmI();
	daniel = joao;
	daniel.whoAmI();
	return 0;
}

/* 
VIRTUAL INHERITING -> solve multiple inheritance
Ensures that there is only one instance of the base class (ClapTrap) in
the derived classes (they share only one instance), even if there are multiple
paths to inherit from ClapTrap in a diamond shaped inheritance structure

-Wshadow (warning) -Wno-shadow (disable)
Variable shadowing occurs when a local variable has the same name as a variable
in a higher scope (in another class), so the local variable "shadows" or
"hides" the outer one, leading to undefined behaviors, because the outer one
is no longer acessible in that scope
*/