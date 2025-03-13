#include "Harl.hpp"

int main(void){
	Harl harl;
	std::string input;
	while (!std::cin.eof()){
		input = "";
		std::cout << "Insert the message you want to print:\n" <<
		"debug, info, warning or error" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof()){
			std::cout << std::endl << RED << "Ctrl+D pressed! Exiting program!" << RESET << std::endl;
			std::exit(0);
		}
		harl.complain(input);
	}
}
