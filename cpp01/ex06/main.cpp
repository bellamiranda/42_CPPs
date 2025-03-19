#include "Harl.hpp"

int main(int argc, char **argv){
	if (argc != 2){
		std::cout << RED << "Please insert one and only one parameter:\nDEBUG, INFO, WARNING, ERROR or any other complain Harl might have" << RESET << std::endl;
		return (EXIT_FAILURE);
	}
	Harl harl;
	harl.complain(argv[1]);
	return (EXIT_SUCCESS);
}