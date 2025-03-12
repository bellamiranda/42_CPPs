#include "Zombie.hpp"

Zombie* newZombie( std::string name ){
	Zombie *z1 = new Zombie(name);
	return (z1);
	//creates a zombie, names it and returns it so you can use out of the func
}
