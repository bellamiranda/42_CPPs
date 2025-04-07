#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed() : value(0){
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i){
	//std::cout << "Int constructor called" << std::endl;
	this->value = i * (1 << Fixed::bits);
}

Fixed::Fixed(const float f){
	//std::cout << "Float constructor called" << std::endl;
	this->value = roundf(f * (1 << Fixed::bits));
}

Fixed::Fixed(const Fixed &f){
	//std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed& Fixed::operator=(const Fixed& other){
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		value = other.value;
	return (*this);
}

Fixed::~Fixed(){
	//std::cout << "Destructor called" << std::endl;
}

//---------------------------------------------------------------------------

int Fixed::getRawBits(void)const{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits(int const raw){
	this->value = raw;
}

float Fixed::toFloat() const {
	return (float)this->value / (1 << bits);
}

//convert fixed-point to int
int Fixed::toInt() const {
	return value >> bits;
}

//---------------------------------------------------------------------------

//overload << operator to print fixed-point as floats
std::ostream& operator<<(std::ostream& buf, const Fixed& fixed){
	buf << fixed.toFloat();
	return buf;
}

bool Fixed::operator>(const Fixed& other){
	return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed& other){
	return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed& other){
	return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed& other){
	return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed& other){
	return this->getRawBits() == other.getRawBits();
}
bool Fixed::operator!=(const Fixed& other){
	return this->getRawBits() != other.getRawBits();
}

//---------------------------------------------------------------------------

Fixed Fixed::operator+(const Fixed &other){
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other){
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other){
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other){
	if (other.getRawBits() == 0){
		std::cout << "Error: divinding by zero" << std::endl;
		return Fixed();
	}
	return Fixed(this->toFloat() / other.toFloat());
}

//---------------------------------------------------------------------------

//increment and return a reference of the instance
Fixed& Fixed::operator++(){
	this->value += 1;
	return *this;
}

//increment but return a copy of the instance that has not been incremented
Fixed Fixed::operator++(int){
	Fixed temp(*this);
	this->value += 1;
	return temp;
}

Fixed& Fixed::operator--(){
	this->value -= 1;
	return *this;
}

Fixed Fixed::operator--(int){
	Fixed temp(*this);
	this->value -= 1;
	return temp;
}

//---------------------------------------------------------------------------

Fixed& Fixed::min(Fixed &a, Fixed &b) {
	if (a.getRawBits() <= b.getRawBits())
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
	if (a.getRawBits() <= b.getRawBits())
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
	if (a.getRawBits() >= b.getRawBits())
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
	if (a.getRawBits() >= b.getRawBits())
		return (a);
	return (b);
}