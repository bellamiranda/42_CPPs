#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Wrong.hpp"

int main()
{
	//AAnimal *aanimal = new AAnimal;
	//AAnimal animal = AAnimal;

	int size = 4;
	AAnimal* animals[size];
    for (int i = 0; i < size / 2; i++)
        animals[i] = new Dog();
    for (int i = size / 2; i < size; i++)
        animals[i] = new Cat();
    for (int i = 0; i < size; i++)
        animals[i]->makeSound();
    for (int i = 0; i < size; i++)
        delete animals[i];
}

/* 
ABSTRACT CLASSES -> class that cannot be instantiated
Usually used as a base class, with pure virtual functions -> derived
classes MUST implement them
virtual void makeSound() const = 0;
= 0 means it is PURE VIRTUAL -> has no implementation in the base abstract class

INTERFACES -> class that contains pure virtual fuctions and no data members
defines some rules that the derived classes must follow on what must be done
*/