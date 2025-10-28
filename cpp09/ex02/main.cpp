#include "PmergeMe.hpp"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Error: Invalid arguments" << std::endl;
        return 1;
    }
    std::vector<int> vector;
    std::deque<int> deque;
    for(int i = 1; i < argc; i++) {
        char *str_end;
        long number = std::strtol(argv[i] , &str_end, 10);
        if (*str_end != '\0' || number < 0 || number > INT_MAX) {
            std::cout << "Error: Invalid number" << std::endl;
            return 1;
        }
        vector.push_back(number);
        deque.push_back(number);
    }
    try {
        PmergeMe pmerge_me(vector, deque);
        pmerge_me.fordJohnsonSort();
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}