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
	for (int i = 0; i < 6; i++)
		delete array[i];

	std::cout << std::endl << RED " ----- TEST BRAIN ----- " RESET << std::endl;
	Cat *test = new Cat();
	for (int i = 0; i < 102; i++)
    	test->setBrainIdea("Idea");
	delete test;
	std::cout << std::endl;

	Cat *cat = new Cat();
	Dog *dog = new Dog();
	cat->displayBrainIdeas();
	cat->setBrainIdea("Knock everything off the table at 3am");
	cat->setBrainIdea("Stare at the wall like there is a ghost");
	cat->setBrainIdea("Nap in the sun for 6 hours straight");
	cat->setBrainIdea("Plan world domination - after a snack");
	cat->setBrainIdea("Chase absolutely nothing with full intensity");
	cat->displayBrainIdeas();
	dog->setBrainIdea("Did someone say walk?!");
	dog->setBrainIdea("Protect the house from the evil mailman");
	dog->setBrainIdea("Roll in something smelly");
	dog->setBrainIdea("Wag tail so hard the butt wiggles too");
	dog->setBrainIdea("Stick head out of the window for ultimate happiness");
	dog->displayBrainIdeas();

	std::cout << std::endl << RED " ----- TEST DEEP COPIES ----- " RESET << std::endl;
	Cat *cat1 = new Cat();
	*cat1 = *cat;
	cat1->setBrainIdea("miaauuu");
	std::cout << RED " ----- CAT1 IDEAS ----- " RESET << std::endl;
	cat1->displayBrainIdeas();
	std::cout << std::endl;
	
	Cat *cat2 = new Cat(*cat);
	cat2->setBrainIdea("copy constructor test");
	std::cout << RED " ----- CAT2 IDEAS ----- " RESET << std::endl;
	cat2->displayBrainIdeas();
	std::cout << std::endl;

	std::cout << RED " ----- ORIGINAL CAT IDEAS ----- " RESET << std::endl;
	cat->displayBrainIdeas();
	std::cout << std::endl;

	Dog* dog2 = new Dog(*dog);
	dog2->setBrainIdea("Woooff");
	std::cout << RED " ----- DOG1 IDEAS ----- " RESET << std::endl;
	dog2->displayBrainIdeas();
	std::cout << std::endl << RED " ----- ORIGINAL DOG IDEAS ----- " RESET << std::endl;
	dog->displayBrainIdeas();
	std::cout << std::endl;

	Animal *arrayOfAnimals[2] = {cat, dog};
	arrayOfAnimals[0]->makeSound();
	arrayOfAnimals[1]->makeSound();

	delete cat; delete dog; delete cat1; delete cat2; delete dog2;
	return 0;
}

/* 
SHALLOW COPY -> share the same data, both original and copy points to
the same memory. Changing one affects the other.
(Default copy constructor and assignment operator do shallow copy unless overridden)
DEEP COPY -> creates a full independent copy of dynamic data (heap memory). 
Each object has its own copy of the data, so changing one won't
affect the other
*/