#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _vector(), _deque(), _vectorSorted(), _dequeSorted() {}

PmergeMe::PmergeMe(const std::vector<int> &vec, const std::deque<int> &deq)
	: _vector(vec), _deque(deq), _vectorSorted(), _dequeSorted() {}

PmergeMe::PmergeMe(const PmergeMe &other) : _vector(other._vector), _deque(other._deque),
	_vectorSorted(other._vectorSorted), _dequeSorted(other._dequeSorted) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		_vector = other._vector;
		_deque = other._deque;
		_vectorSorted = other._vectorSorted;
		_dequeSorted = other._dequeSorted;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::fordJohnsonSort() {
    std::cout << "Before: ";
    printContainer(_vector);

    clock_t startVector = clock();
    _vectorSorted = sortVector(_vector);
    clock_t finishVector = clock();
    double timeToSortVector = static_cast<double>(finishVector - startVector) / CLOCKS_PER_SEC * 1000000;

    clock_t startDeque = clock();
    _dequeSorted = sortDeque(_deque);
    clock_t finishDeque = clock();
    double timeToSortDeque = static_cast<double>(finishDeque - startDeque) / CLOCKS_PER_SEC * 1000000;

    std::cout << "After: ";
    printContainer(_vectorSorted);

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Time to process a range of " << _vectorSorted.size() << " elements with std::vector : " << timeToSortVector << " us" << std::endl;
    std::cout << "Time to process a range of " << _dequeSorted.size() << " elements with std::deque : " << timeToSortDeque << " us" << std::endl;
}

std::vector<size_t> PmergeMe::jacobsthalSequence(size_t limit) {
	std::vector<size_t> sequence;
	if (limit == 0)
		return sequence;
	if (limit >= 1)
		sequence.push_back(1);
	if (limit >= 2)
		sequence.push_back(3);
	for (size_t i = 2; ; ++i) {
        if (sequence.size() < 2)
			break;
        size_t next = sequence[i-1] + 2 * sequence[i-2];
        if (next > limit)
			break;
        sequence.push_back(next);
    }
	return sequence;
}

//ALGORITHM USING VECTOR ----------------------------------------------------

size_t PmergeMe::findIndexVector(const std::vector<int> &vec, int value) {
	size_t low = 0;
	size_t high = vec.size();

	while (low < high) {
		size_t middle = (low + high) / 2;
		if (vec[middle] < value)
			low = middle + 1;
	    else 
	    	high = middle;
	}
    return low;
}

std::vector<int> PmergeMe::sortVector(std::vector<int> numbers){
    int rest = -1;

    if(numbers.size() <= 1)
        return numbers;

    if (numbers.size() % 2 != 0) {
        rest = numbers.back();
        numbers.pop_back();
    }

    std::vector<std::pair<int, int> > current_pairs;
    for (size_t i = 0; i < numbers.size(); i += 2) {
        if (numbers[i] < numbers[i + 1])
            current_pairs.push_back(std::make_pair(numbers[i], numbers[i + 1]));
        else
            current_pairs.push_back(std::make_pair(numbers[i + 1], numbers[i]));
    }

    std::vector<int> biggers;
    for (size_t i = 0; i < current_pairs.size(); i++)
		biggers.push_back(current_pairs[i].second);
	std::vector<int> sorted_biggers = sortVector(biggers);


    std::vector<int> main_chain = sorted_biggers;
	std::vector<bool> used(current_pairs.size(), false);
    if (!sorted_biggers.empty()) {
        int first_smaller = -1;
        for (size_t i = 0; i < current_pairs.size(); i++) {
            if(!used[i] && current_pairs[i].second == sorted_biggers[0]) {
                first_smaller = current_pairs[i].first;
				used[i] = true;
                break;
            }
        }
        if (first_smaller != -1) {
            size_t position = findIndexVector(main_chain, first_smaller);
            main_chain.insert(main_chain.begin() + position, first_smaller);
        }
    }
    
    std::vector<int> pendent_elements;
    for (size_t i = 1; i < sorted_biggers.size(); i++) {
        for(size_t j = 0; j < current_pairs.size(); j++) {
            if (!used[j] && current_pairs[j].second == sorted_biggers[i]) {
                pendent_elements.push_back(current_pairs[j].first);
				used[j] = true;
                break;
            }
        }
    }

    std::vector<size_t> jacobsthalSeq = jacobsthalSequence(pendent_elements.size());
    size_t last_inserted = 0;
    for (size_t i = 0; i < jacobsthalSeq.size(); i++)
    {
        size_t group_start = jacobsthalSeq[i];
        if (group_start > pendent_elements.size())
            group_start = pendent_elements.size();
        for (size_t j = group_start; j > last_inserted; j--) {
            size_t position = findIndexVector(main_chain, pendent_elements[j - 1]);
            main_chain.insert(main_chain.begin() + position, pendent_elements[j - 1]);
        }
        last_inserted = group_start;
    }
	//insert any pending elements not covered by jacobsthal
	for (size_t j = pendent_elements.size(); j > last_inserted; j--) {
    	size_t position = findIndexVector(main_chain, pendent_elements[j - 1]);
    	main_chain.insert(main_chain.begin() + position, pendent_elements[j - 1]);
	}

    if (rest >= 0) {
        size_t position = findIndexVector(main_chain, rest);
        main_chain.insert(main_chain.begin() + position, rest);
    }
    return main_chain;
}

//ALGORITHM USING DEQUE 

size_t PmergeMe::findIndexDeque(const std::deque<int> &deq, int value) {
    size_t low = 0;
    size_t high = deq.size();

    while (low < high) {
        size_t middle = (low + high) / 2;
        if (deq[middle] < value)
            low = middle + 1;
        else 
            high = middle;
    }
    return low;
}

std::deque<int> PmergeMe::sortDeque(std::deque<int> numbers) {
    int rest = -1;

    if(numbers.size() <= 1)
        return numbers;

    if (numbers.size() % 2 != 0) {
        rest = numbers.back();
        numbers.pop_back();
    }

    std::vector<std::pair<int, int> > current_pairs;
    for (size_t i = 0; i < numbers.size(); i += 2) {
        if (numbers[i] < numbers[i + 1])
            current_pairs.push_back(std::make_pair(numbers[i], numbers[i + 1]));
        else
            current_pairs.push_back(std::make_pair(numbers[i + 1], numbers[i]));
    }

    std::deque<int> biggers;
    for (size_t i = 0; i < current_pairs.size(); i++)
		biggers.push_back(current_pairs[i].second);
	std::deque<int> sorted_biggers = sortDeque(biggers);


    std::deque<int> main_chain = sorted_biggers;
	std::vector<bool> used(current_pairs.size(), false);
    if (!sorted_biggers.empty()) {
        int first_smaller = -1;
        for (size_t i = 0; i < current_pairs.size(); i++) {
            if(!used[i] && current_pairs[i].second == sorted_biggers[0]) {
                first_smaller = current_pairs[i].first;
				used[i] = true;
                break;
            }
        }
        if (first_smaller != -1) {
            size_t position = findIndexDeque(main_chain, first_smaller);
            main_chain.insert(main_chain.begin() + position, first_smaller);
        }
    }
    
    std::deque<int> pendent_elements;
    for (size_t i = 1; i < sorted_biggers.size(); i++) {
        for(size_t j = 0; j < current_pairs.size(); j++) {
            if (!used[j] && current_pairs[j].second == sorted_biggers[i]) {
                pendent_elements.push_back(current_pairs[j].first);
				used[j] = true;
                break;
            }
        }
    }

    std::vector<size_t> jacobsthalSeq = jacobsthalSequence(pendent_elements.size());
    size_t last_inserted = 0;
    for (size_t i = 0; i < jacobsthalSeq.size(); i++) {
        size_t group_start = jacobsthalSeq[i];
        if (group_start > pendent_elements.size())
            group_start = pendent_elements.size();
        for (size_t j = group_start; j > last_inserted; j--) {
            size_t position = findIndexDeque(main_chain, pendent_elements[j - 1]);
            main_chain.insert(main_chain.begin() + position, pendent_elements[j - 1]);
        }
        last_inserted = group_start;
    }
	//insert any pending elements not covered by jacobsthal
	for (size_t j = pendent_elements.size(); j > last_inserted; j--) {
    	size_t position = findIndexDeque(main_chain, pendent_elements[j - 1]);
    	main_chain.insert(main_chain.begin() + position, pendent_elements[j - 1]);
	}

    if (rest >= 0) {
        size_t position = findIndexDeque(main_chain, rest);
        main_chain.insert(main_chain.begin() + position, rest);
    }
    return main_chain;
}