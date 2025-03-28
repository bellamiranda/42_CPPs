#pragma once
#ifndef CLASS_HPP
#define CLASS_HPP

#include <iostream>

class Fixed{
private:
	int value;
	static const int bits = 8;
public:
	Fixed();
	Fixed(const Fixed& copy);
	Fixed& operator=(const Fixed& other);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#define RESET	"\033[0m"
#define GREEN	"\033[1;32m"
#define YELLOW	"\033[1;38;5;220m"
#define ORANGE	"\033[1;38;5;208m"
#define RED		"\033[31;1m"
#define CYAN	"\033[36;1m"
#define MGT		"\033[1;35m"

#endif