#pragma once
#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
protected:
	std::string _ideas[100];
public:
	Brain();
	Brain(const Brain& copy);
	Brain& operator=(const Brain& copy);
	virtual ~Brain();

	void setIdea(const std::string newIdea);
	std::string getIdea(int index) const;
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