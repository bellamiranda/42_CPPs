#pragma once
#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class Harl{

public:
	Harl();
	~Harl();
	void complain( std::string level );
private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );

};

#define RESET	"\033[0m"
#define GREEN	"\e[0;32m"
#define CYAN	"\033[36;1m"
#define MGT		"\033[1;35m"
#define RED		"\033[31;1m"

#endif