#include "easyfind.hpp"

void testVector(int nbr);
void testList(int nbr);
void testDeque(int nbr);

int main() {
	std::cout << "Choose a container type to work with: \n1 - Vector\n2 - List\n3 - Deque" << std::endl;
	int i; std::cin >> i;

	std::cout << "Digit a number to search inside the container: (1 to 10): ";
	int nbr; std::cin >> nbr;
	
	switch (i) {
		case 1:
			testVector(nbr);
			break;
		case 2:
			testList(nbr);
			break;
		case 3:
			testDeque(nbr);
			break;
		default:
			std::cerr << RED "Invalid container option\nUse numbers 1, 2 or 3" RESET << std::endl;
			break;
	}
	return 0;
}

void testVector(int nbr) {
    std::vector<int> vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	std::cout << "\nVector contents:" << std::endl;
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << std::endl; 

    try {
        easyfind(vec, nbr);
		std::cout << GREEN "\nFound: " << nbr << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cerr << RED "\nError: " << e.what() << RESET << std::endl;
    }
}

void testList(int nbr) {
    std::list<int> lst;

	lst.push_back(4);
	lst.push_back(5);
	lst.push_back(6);

	std::cout << "\nList contents:" << std::endl;
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << std::endl;

    try {
        easyfind(lst, nbr);
		std::cout << GREEN "\nFound: " << nbr << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cerr << RED "\nError: " << e.what() << RESET << std::endl;
    }
}

void testDeque(int nbr) {
    std::deque<int> deq;

	deq.push_back(7);
	deq.push_back(8);
	deq.push_back(9);
	deq.push_back(10);

    std::cout << "\nDeque contents:" << std::endl;
	for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); it++)
		std::cout << *it << std::endl;

    try {
        easyfind(deq, nbr);
		std::cout << GREEN "\nFound: " << nbr << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cerr << RED "\nError: " << e.what() << RESET << std::endl;
    }
}