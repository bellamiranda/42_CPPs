#include "Array.hpp"

int main(void) {
	std::cout << GREEN "Subject test" RESET << std::endl;
	int *a = new int();
	//int *g = new int;
	std::cout << "a: " << *a << std::endl;
	//std::cout << "g: " << *g << std::endl;
	*a = 42;
	std::cout << "a: " << *a << std::endl;
	delete a;
	//delete g;
	
	std::cout << GREEN "\nParameterized constructor test" RESET << std::endl;
	Array<int> b(5);
	for (unsigned int i = 0; i < b.size(); ++i)
		b[i] = i * 2;
	for (unsigned int i = 0; i < b.size(); ++i)
		std::cout << "b[" << i << "]: " << b[i] << std::endl;

	std::cout << GREEN "\nCopy constructor test" RESET << std::endl;
	Array<int> c(b);
	for (unsigned int i = 0; i < c.size(); ++i)
		std::cout << "c[" << i << "]: " << c[i] << std::endl;

	std::cout << GREEN "\nAssignment operator test" RESET << std::endl;
	Array<int> d;
	d = c;
	for (unsigned int i = 0; i < d.size(); ++i)
		std::cout << "d[" << i << "]: " << d[i] << std::endl;

	std::cout << GREEN "\nOut of range test" RESET << std::endl;
	try {
		std::cout << b[10] << std::endl;//is out of range, should throw an exception
	} catch (const std::out_of_range& e) {
		std::cerr << RED "Exception caught: " RESET << e.what() << std::endl;
	}

	std::cout << GREEN "\nConst correctness test" RESET << std::endl;
	const Array<int> e = c;
	for (unsigned int i = 0; i < e.size(); ++i)
		std::cout << "e[" << i << "]: " << e[i] << std::endl;

	return 0;
}