#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Wrong.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << RED << "\n ----- TEST WIHTOUT POINTER ----- " << RESET << std::endl;
	const Animal test = Cat(); //object slicing
	std::cout << test.getType() << " " << std::endl;
	test.makeSound();

	std::cout << RED << "\n ----- TEST WRONG ANIMALS ----- " << RESET << std::endl;
	const WrongAnimal* wrong_a = new WrongAnimal();
	const WrongAnimal* wrong_c = new WrongCat();
	std::cout << wrong_a->getType() << " " << std::endl;
	std::cout << wrong_c->getType() << " " << std::endl;
	wrong_a->makeSound();
	wrong_c->makeSound();

	delete meta; delete j; delete i; delete wrong_a; delete wrong_c;
	return 0;
}

/* 
POLYMORPHISM
Treat object of different derived classes as if they were of the same 
base class type - store a dog or a cat inside animal and when you call
a virtual function like makeSound, the correct version will be called based
on the type of the object

VIRTUAL DESTRUCTOR when using polimorphism with pointers (on the base class)
so it can destruct the derived object properly and not only the base 
(if the class has virtual functions, the destructor should be virtual too)

USE OF THE POINTER (Animal*) -> dynamic polimorphism
guarantee that it'll use the actual type of object and it's functions overrided

VIRTUAL FUNCTION
Is declared on the base class, but is overridden by the derived classes
Runtime polymorphism!!!!!!
makeSound()override -> will guarantee even if there is a small mistake (C++11)

virtual void makeSound()const -> read-only
This const means that the method doesnt modify the object on which is called,
and can be called on const objects, like on this main

OBJECT SLICING -> when an object of a derived class is assgined to a base class
object, causing the derived part to be "sliced off" and onlu the base class 
portion to remain. That's why, without the pointer, the type is cat (overridden)
but the sound is from the animal class.
*/