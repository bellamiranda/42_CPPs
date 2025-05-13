#pragma once
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
private:
	std::string _name;
	AMateria* _inventory[4]; // can equip up to 4
public:
	Character();
	Character(std::string const & name);
	Character(const Character& copy);
	Character& operator=(const Character& copy);
	~Character();
	
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

	void copyInventory(const Character &src);
};

#endif