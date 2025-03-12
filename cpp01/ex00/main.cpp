#include "Zombie.hpp"

int main(int argc, char **argv){
	for (int i = 1; i < argc; i++){
		Zombie *heap = newZombie(std::string(argv[i]) + " HEAP");
		heap->announce();
		randomChump(std::string(argv[i]) + " STACK");
		delete (heap);
	}
	return (0);
}

//determine in which case it is better to allocate zombies
//on the stack or the heap