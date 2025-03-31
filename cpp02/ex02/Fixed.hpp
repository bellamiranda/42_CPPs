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
	~Fixed();
	//Fixed& operator=(const Fixed& other);
	float toFloat() const;
	bool operator>(const Fixed& other);
	bool operator<(const Fixed& other);//criar o <<
	bool operator>=(const Fixed& other);
	bool operator<=(const Fixed& other);
	bool operator==(const Fixed& other);
	bool operator!=(const Fixed& other);
	Fixed& operator+(const Fixed& other);
	Fixed& operator-(const Fixed& other);
	Fixed& operator*(const Fixed& other);
	Fixed& operator/(const Fixed& other);
	Fixed operator++();
	Fixed operator++(int);
	Fixed operator--();
	Fixed operator--(int);
	static Fixed& min(Fixed& a, Fixed& b);
	static Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static Fixed& max(const Fixed& a, const Fixed& b);
};

#endif