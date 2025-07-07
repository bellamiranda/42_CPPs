#include "Classes.hpp"

Base* generate(void) {
	int random = rand() % 3;
	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else
		return new C();
}

//in the pointer case, it returns NULL if the cast fails
void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << CYAN "A Pointer" RESET << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << CYAN "B Pointer" RESET << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << CYAN "C Pointer" RESET << std::endl;
	else if (p == NULL)
		std::cout << RED "Unknown Pointer" RESET << std::endl;
}

//in the reference case, it throws std::bad_cast if the cast fails
void identify(Base& p) {
	try {
		A& a = dynamic_cast<A&>(p);
		std::cout << MGT "A Reference" RESET << std::endl;
		(void)a;
		return;
	} catch (...) {} //catch-all 
	try {
		B& b = dynamic_cast<B&>(p);
		std::cout << MGT "B Reference" RESET << std::endl;
		(void)b;
		return;
	} catch (...) {}
	try {
		C& c = dynamic_cast<C&>(p);
		std::cout << MGT "C Reference" RESET << std::endl;
		(void)c;
		return;
	} catch (...) {}
	std::cout << RED "Unknown Reference" RESET << std::endl;
}