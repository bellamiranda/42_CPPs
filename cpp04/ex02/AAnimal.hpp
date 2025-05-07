#pragma once
#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal {
protected:
	std::string _type;
public:
	AAnimal();
	AAnimal(const AAnimal& copy);
	AAnimal& operator=(const AAnimal& copy);
	virtual ~AAnimal();
	
	virtual std::string getType()const;
	virtual void makeSound()const = 0;
};

#define RESET	"\033[0m"
#define GREEN	"\033[1;32m"
#define YELLOW	"\033[1;38;5;220m"
#define ORANGE	"\033[1;38;5;208m"
#define RED		"\033[31;1m"
#define CYAN	"\033[36;1m"
#define MGT		"\033[1;35m"
#define BLINK	"\e[5m"

#endif