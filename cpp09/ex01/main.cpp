#include "RPN.hpp"

int main(int argc, char **argv) {
	RPN rpn;
    if (argc == 2) {
        try {    
            rpn.process(argv[1]);
        }
        catch(const std::exception& e) {
            std::cerr << RED << e.what() << RESET << std::endl;
            return 1;
        }
    }
    else
        std::cout << "Error: Invalid argument" << std::endl;
    return 0;
}