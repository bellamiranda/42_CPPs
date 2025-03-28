#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}


/* 
DEFAULT CONSTRUCTOR - initializes objects (not builtin types)
	Example(int val){
		ptr = new int (val);}

COPY CONSTRUCTOR - initilizes a new obj as a copy of the existing one
* if the class has pointers, need to copy dinamicallu alloc memory
	Example(const Example& other){
		ptr = new int (*other.ptr);}

COPY ASSIGNMENT OPERATOR (operator=) - assigning one existing obj to another
	Example& operator=(const Example& other){
		if (this != &other){
			delete ptr;HARL_HPP
#define HARL_HPPther.ptr);}
		return *this;}
* called when an already existing object is assigned a new value from another
object of the same class
	obj1(10);
	obj2(20);
	obj2 = obj1;

DESTRUCTOR - called automatically when an obj goes out of scope or is deleted
 */