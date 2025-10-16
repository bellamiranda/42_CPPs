#include "Span.hpp"

Span::Span() : _N(0) {}

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span &src) {
	*this = src;
}

Span::~Span() {}

Span &Span::operator=(const Span &src) {
	if (this != &src) {
		_N = src._N;
		_v.clear();
		_v.insert(_v.end(), src._v.begin(), src._v.end());
	}
	return *this;
}

void Span::addNumber(int nbr) {
	if (_v.size() >= _N)
		throw std::runtime_error("Not enough space");
	_v.push_back(nbr);
}

int Span::shortestSpan() const {
	if (_v.size() < 2)
		throw std::runtime_error("Not enough numbers stored to find shortest span");

	std::vector<int> sorted = _v;
	std::sort(sorted.begin(), sorted.end());
	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sorted.size(); i++) {
		int span = std::abs(sorted[i] - sorted[i - 1]);//avoid negative
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

int Span::longestSpan() const {
	if (_v.size() < 2)
		throw std::runtime_error("Not enough numbers stored to find longest span");
	int maxValue = *std::max_element(_v.begin(), _v.end());
	int minValue = *std::min_element(_v.begin(), _v.end());
	return maxValue - minValue;
}