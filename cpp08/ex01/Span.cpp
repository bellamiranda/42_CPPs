#include "Span.hpp"

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span &src) {
	
}

int Span::shortestSpan() const {

}

int Span::longestSpan() const {
	int maxValue = *std::max_element(_v.begin(), _v.end());
	int minValue = *std::min_element(_v.begin(), _v.end());
	return maxValue - minValue;
}