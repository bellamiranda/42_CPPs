#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <cstdlib>//atoi
#include <sstream>//ostringstream

class Zombie {

public:
	Zombie();
	~Zombie();
	void	announce();
	void	setName(std::string name);
private:
	std::string name;
	
};

Zombie *zombieHorde( int N, std::string name );

#define RESET	"\033[0m"
#define RED		"\033[31;1m"
#define CYAN	"\033[36;1m"
#define MGT		"\033[1;35m"

#endif