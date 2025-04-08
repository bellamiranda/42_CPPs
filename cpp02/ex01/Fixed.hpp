#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>//roundf

class Fixed{
private:
	int value;
	static const int bits = 8;
public:
	Fixed();
	Fixed(const int i);
	Fixed(const float f);
	Fixed(const Fixed& copy);
	Fixed& operator=(const Fixed& other);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat() const;
	int toInt() const;
};

std::ostream& operator<<(std::ostream& buf, const Fixed& fixed);

#endif