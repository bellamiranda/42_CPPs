#pragma once
#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
private:
	Brain* _brain;
public:
	Cat();
	Cat(const Cat& copy);
	Cat& operator=(const Cat& copy);
	~Cat();

	void makeSound()const;
	void setBrainIdea(std::string newIdea);
	std::string *getBrainIdeas();
	void displayBrainIdeas();
};

#endif