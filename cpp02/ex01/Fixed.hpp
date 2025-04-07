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
	Fixed(const int num);
	Fixed(const float num);
	Fixed(const Fixed& copy);
	Fixed& operator=(const Fixed& other);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat() const;
	int toInt() const;
	friend std::ostream& operator<<(std::ostream& buf, const Fixed& fixed);
};
//friend functions allow non-member functions to access private members
//<< can access value without a getter

#endif