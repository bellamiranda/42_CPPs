#pragma once
#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
	Brain* _brain;
public:
	Dog();
	Dog(const Dog& copy);
	Dog& operator=(const Dog& copy);
	~Dog();

	void makeSound()const;
	void setBrainIdea(std::string newIdea);
	std::string *getBrainIdeas();
	void displayBrainIdeas();
};

#endif