#pragma once
#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon{

public:
	Weapon(std::string type);
	~Weapon();
	const std::string &getType();
	void setType(std::string newValue);
private:
	std::string _type;

};

#define RESET	"\033[0m"
#define RED		"\033[31;1m"
#define CYAN	"\033[36;1m"
#define MGT		"\033[1;35m"
#define GREEN	"\e[0;32m"

#endif