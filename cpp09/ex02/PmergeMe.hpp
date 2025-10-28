#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <string>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <climits>

class PmergeMe {
public:
	PmergeMe();
	PmergeMe(const std::vector<int> &vec, const std::deque<int> &deq);
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	void fordJohnsonSort();
	std::vector<size_t> jacobsthalSequence(size_t limit);

    size_t findIndexVector(const std::vector<int> &vector_container, int value);        
	std::vector<int> sortVector(std::vector<int> numbers);
	
	size_t findIndexDeque(const std::deque<int> &deque_container, int value);
	std::deque<int> sortDeque(std::deque<int> numbers);
private:
	std::vector<int> _vector;
	std::deque<int> _deque;
	std::vector<int> _vectorSorted;
	std::deque<int> _dequeSorted;
};

template <typename T>
void printContainer(const T& cont) {
    typename T::const_iterator it;
    for (it = cont.begin(); it != cont.end(); ++it)
        std::cout << *it << ' ';
    std::cout << std::endl;
}

//Ford-Johnson algorithm -> min comparissons sorting
//Jacob-Sthal sequence (Jn = Jn-1 + Jn-2 with J0 = 1 and J1 = 1)
//Choose and process pairs recursively
//Reduce comparisson using an optimized insertion order

#define RESET	"\033[0m"
#define GREEN	"\033[1;32m"
#define YELLOW	"\033[1;38;5;220m"
#define ORANGE	"\033[1;38;5;208m"
#define RED		"\033[31;1m"
#define CYAN	"\033[36;1m"
#define MGT		"\033[1;35m"
#define BLINK	"\e[5m"

#endif