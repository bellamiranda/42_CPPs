#include "iter.hpp"

int main(void) {
	int array[] = { 0, 1, 2, 3, 4, 5 };
	std::string strArray[] = { "Hello", "World", "42", "C++", "is", "awesome" };
	char charArray[] = { 'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd' };

	iter(array, 6, print<int>);
	std::cout << std::endl;
	iter(strArray, 6, print<std::string>);
	std::cout << std::endl;
	iter(charArray, 11, print<char>);
	return 0;
}