#include "Span.hpp"

int main() {
	std::cout << MGT << "----- SUBJECT TESTS -----" << RESET << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	//to try exceptions:
	//1. add a number to a full Span (change size to 4)
	//2. try to get span with less than 2 numbers (min and max)
	std::cout << MGT << "\n----- MY OWN TESTS -----" << RESET << std::endl;
	try {
		Span sp2 = Span(10);
		sp2.addNumber(5);
		sp2.addNumber(40);
		sp2.addNumber(15);
		sp2.addNumber(35);
		sp2.addNumber(27);
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << RED << "Erro: " << e.what() << RESET << std::endl;
	}

	std::cout << MGT << "\n----- RANDOM 10000 NUMBERS TEST -----" << RESET << std::endl;
	try {
        Span sp3(10000);

        std::srand(std::time(NULL));
        for (int i = 0; i < 10000; ++i)
            sp3.addNumber(std::rand());

        std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp3.longestSpan() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
	
	return 0;
}
