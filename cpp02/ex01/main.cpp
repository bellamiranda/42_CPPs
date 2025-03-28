#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}

/* 
FLOATING-POINT (rouding errors)
store values in scientific notation
value = sign x mantissa x 2^
5.75 -> binary = 101.11
	 -> scientific notation = 1.0111 x 2^2
pros: uses dynamic precision (adapts to different values)
	can store very large and very small numbers
cons: imprecise due to rouding errors
	more complex and slower in calculations

FIXED-POINT (more precise -> financial calculations, embedded systems)
performance > precision (arithmetic is faster)
store fixed number of decimal places using int representation
5.75 -> binary integer = 101110000
	 -> scaling factor = 1/2^8 = 0.00390625
	 -> stored int = 5.75 x 256 = 1472
pros: precise (avoid floating-points rouding errors)
	faster calculations (int based math)
cons: limited range (cannot store very large/small numbs)
	requires manual scaling (dividing/multiplying by a factor)

float->fixed
num * (1 << 8)
fixed->float
value / (1 << 8)

TYPE	|	REPRESENTATION	|	PRECISION	|	RANGE	|	EXAMPLE			|
int		|	whole numbs		|	exact		|	limited	|	5, -3, 42		|
float	|	scientific not	|	approximate	|	large	| 3.14159, 0.1, -2.5 |
fixed	|	scaled int base	|	exact bits	|	limited	| 42.42 (10883 - 8 bit) |
 */