#include <iostream>
#include <string>

int main(void){
	std::string a = "HI THIS IS BRAIN";
	std::string *stringPTR = &a;
	std::string &stringREF = a;
	std::cout << "Memory address of string: " << &a << std::endl;
	std::cout << "Memory address of stringPTR: " << &stringPTR << std::endl;
	std::cout << "Memory address of stringREF: " << &stringREF << std::endl << std::endl;
	std::cout << "Value of string: " << a << std::endl;
	std::cout << "Value of stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value of stringREF: " << stringREF << std::endl;
}

//reference is like an alias, pointer is a separate object
//is like another name to the variable it refers to
//any change to ref affect the variable because they are the same memory location
//can't be changed after initialization
//a pointer can point to another variable after
//ref cannot be null, a pointer can