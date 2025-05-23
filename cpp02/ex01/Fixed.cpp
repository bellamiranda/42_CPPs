#include "Fixed.hpp"

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

//converts int to fixed-point
Fixed::Fixed(const int i){
	std::cout << "Int constructor called" << std::endl;
	this->value = i << bits;
}

//converts floating-point to fixed-point
Fixed::Fixed(const float f){
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(f * (1 << bits));
}

Fixed::Fixed(const Fixed& copy){
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed& Fixed::operator=(const Fixed& other){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		value = other.value;
	return (*this);
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void)const{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits(int const raw){
	this->value = raw;
}

//convert fixed-point to float
float Fixed::toFloat() const {
	return (float)value / (1 << bits);
}

//convert fixed-point to int
int Fixed::toInt() const {
	return value >> bits;
}

//overload << operator to print fixed-point as floats
std::ostream& operator<<(std::ostream& buf, const Fixed& fixed){
	buf << fixed.toFloat();
	return buf;
}


/* 
BITWISE OPPERATIONS
left shift (<<) - multiply by power of 2
	5 << 3 = 5 x 2^3 = 40
	decimal - 5 | binary - 00000101 | shift 3 - 00101000 = 40
right shift (>>) - divide by power of 2
	40 >> 3 = 40 / 2^3 = 5
	decimal - 40 | binary - 00101000 | shift 3 - 00000101 = 5
 */