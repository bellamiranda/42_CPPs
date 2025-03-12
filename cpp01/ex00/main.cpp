#include "Zombie.hpp"

int main(int argc, char **argv){
	for (int i = 1; i < argc; i++){
		Zombie *heap = newZombie("(HEAP) " + std::string(argv[i]));
		heap->announce();
		randomChump("(STACK) " + std::string(argv[i]));
		delete (heap);
	}
	return (0);
}

//determine in which case it is better to allocate zombies
//on the stack or the heap (stack is destroyed first)