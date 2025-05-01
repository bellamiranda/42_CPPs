#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Wrong.hpp"

int main()
{
	std::cout << RED " ----- ARRAY OF ANIMALS ----- " RESET << std::endl;
	Animal *array[6] = {new Dog, new Dog, new Dog, new Cat, new Cat, new Cat};
	for (int i = 0; i < 6; i++)
		array[i]->makeSound();

	std::cout << std::endl << RED " ----- TEST BRAIN ----- " RESET << std::endl;
	Animal cat = Cat();
	Animal dog = Dog();

	//test if the copies are shallow


	for (int i = 0; i < 6; i++)
		delete array[i];
}

/* 
SHALLOW COPY -> share the same data, both original and copy points to
the same memory. Changing one affects the other.
(Default copy constructor and assignment operator do shallow copy unless overridden)
DEEP COPY -> creates a full independent copy of dynamic data. Each object has
its own copy of the data, so changing one won't affect the other
*/