#include "Zombie.hpp"

Zombie* newZombie( std::string name ){
	Zombie *heap = new Zombie(name);
	return (heap);
	//creates a zombie (in the heap), names it and returns it
	//so you can use out of the function
}
