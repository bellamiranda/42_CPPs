#include "Fixed.hpp"

Fixed::Fixed() : value(0){
}

Fixed::Fixed(const int num) : value(num){
}

Fixed::~Fixed(){
}

float Fixed::toFloat() const {
	return (float)value / (1 << bits);
}

bool Fixed::operator>(const Fixed& other){
	return value > other.value;
}

bool Fixed::operator<(const Fixed& other){
	return value < other.value;
}

bool Fixed::operator>=(const Fixed& other){
	return value >= other.value;
}

bool Fixed::operator<=(const Fixed& other){
	return value <= other.value;
}

bool Fixed::operator==(const Fixed& other){
	return value == other.value;
}
bool Fixed::operator!=(const Fixed& other){
	return value != other.value;
}

