#pragma once
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
private:
	std::string _name;
	int _hitPoints;
	int _energyPoints;
	int _attackDamage;
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& copy);
	ClapTrap& operator=(const ClapTrap& copy);
	~ClapTrap();

	std::string getName()const;
	int getHitPoints()const;
	int getEnergyPoints()const;
	int getAttackDamage()const;
	void setAttackDamage(int amount);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void displayHealth();
};

#define RESET	"\033[0m"
#define GREEN	"\033[1;32m"
#define YELLOW	"\033[1;38;5;220m"
#define ORANGE	"\033[1;38;5;208m"
#define RED		"\033[31;1m"
#define CYAN	"\033[36;1m"
#define MGT		"\033[1;35m"

#endif