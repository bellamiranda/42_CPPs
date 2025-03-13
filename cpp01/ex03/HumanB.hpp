#pragma once
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "HumanA.hpp"

class HumanB{

public:
	HumanB(std::string _name);
	~HumanB();
	void attack();
	void setWeapon(Weapon &weapon);
private:
	std::string _name;
	Weapon *_weapon;

};

#endif