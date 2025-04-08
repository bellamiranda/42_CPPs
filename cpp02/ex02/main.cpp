#include "Fixed.hpp"

int main( void ) {

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "Some other tests" << std::endl;
	Fixed test1(2);
	Fixed test2(4);
	Fixed test3(0);
	Fixed test4(8);
	Fixed test5(5.4f);
	Fixed test6(1.4f);
	std::cout << test1 + test2 << std::endl;
	std::cout << test1 - test2 << std::endl;
	std::cout << "FLOAT " << test5 - test2 << std::endl;
	std::cout << "FLOAT " << test5 - test6 << std::endl;
	std::cout << test1 * test2 << std::endl;
	std::cout << test2 / test1 << std::endl;
	std::cout << test2 / test3 << std::endl << std::endl;

	std::cout << (test1 > test2) << std::endl;//no
	std::cout << (test1 < test2) << std::endl;//yes
	std::cout << (test4 == (test1 * test2)) << std::endl;//yes
	std::cout << (test4 != test2) << std::endl;//yes
	std::cout << (test4 != (test1 * test2)) << std::endl << std::endl;//no

	std::cout << test1.min(test1, test2) << std::endl;
	std::cout << test1.max(test1, test2) << std::endl;
	std::cout << test1.max(test4, (test1 * test2)) << std::endl;
	
	return 0;
}