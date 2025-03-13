#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	{
		Weapon club = Weapon("umbrella");
		HumanA maria("Maria", club);
		HumanB joao("Joao");
		maria.attack();//maria attacks with umbrella
		//joao.printWeapon();
		joao.attack();//joao doesnt have weapon
		joao.setWeapon(club);
		joao.attack();//joao attacks with umbrella
		Weapon knife = Weapon("knife");
		joao.setWeapon(knife);
		joao.attack();//joao attacks with knife
		club.setType("mouse");
		maria.attack();//maria attacks with mouse
		joao.attack();//joao attacks with knife
		joao.setWeapon(club);
		joao.attack();//joao attacks with mouse
	}
	return 0;
}