#include "Zombie.hpp"

void randomChump( std::string name ){
	Zombie stack(name);
	stack.announce();
	//creates a zombie (in the stack), names it and makes it announce itself
}