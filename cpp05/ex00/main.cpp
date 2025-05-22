#include "Bureaucrat.hpp"

int main(void){
	Bureaucrat sir1("sir1", 100);
	Bureaucrat sir2("sir2", 1);
	Bureaucrat sir3("sir3", 150);
	try {
		sir1.increment();
		sir1.decrement();
		std::cout << sir1 << std::endl;
		std::cout << sir2 << std::endl;
		std::cout << sir3 << std::endl;
		sir2.increment();
		std::cout << sir2 << std::endl;
		sir3.decrement();
	} catch (const std::exception& e) {
		std::cerr << MGT << "EXCEPTION CAUGHT: " << e.what() << std::endl;
	}
	try {
		sir3.decrement();
	} catch (const std::exception& e) {
		std::cerr << MGT << "EXCEPTION CAUGHT: " << e.what() << std::endl;
	}
}
