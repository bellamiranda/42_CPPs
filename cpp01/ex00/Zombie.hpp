#pragma once
#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie {

public:
	Zombie(std::string name);
	~Zombie();
	void	announce( void );

private:
	std::string name;
	
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );


#define RESET	"\033[0m"
#define RED		"\033[31;1m"
#define CYAN	"\033[36;1m"

#endif