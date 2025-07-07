#include "Classes.hpp"

int main(void){
	srand(time(NULL));
	Base* instance1 = generate();
	Base* instance2 = generate();
	Base* instance3 = generate();
	Base* instance4 = generate();
	identify(instance1);
	identify(*instance1);
	std::cout << std::endl;
	identify(instance2);
	identify(*instance2);
	std::cout << std::endl;
	identify(instance3);
	identify(*instance3);
	std::cout << std::endl;
	identify(instance4);
	identify(*instance4);
	delete instance1; delete instance2; delete instance3; delete instance4;
	return 0;
}