#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Wrong.hpp"

int main()
{

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