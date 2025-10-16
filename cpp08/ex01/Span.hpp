#pragma once
#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <exception>
#include <vector>
#include <limits>
#include <cmath>
#include <ctime>
#include <cstdlib>

class Span {
private:
	unsigned int _N;
	std::vector<int> _v;
public:
	Span();
	Span(unsigned int N);
	Span(const Span &src);
	~Span();

	Span &operator=(const Span &src);

	void addNumber(int nbr);
	int shortestSpan() const;
	int longestSpan() const;

	template <typename Iterator>
	void addMultipleNumbers(Iterator begin, Iterator end);
};

template <typename Iterator>
void Span::addMultipleNumbers(Iterator begin, Iterator end) {
	if (std::distance(begin, end) + _v.size() > _N)
		throw std::runtime_error("Not enough space");
	_v.insert(_v.end(), begin, end);
}

/* 
Vector: random access by index, easy iteration and sort (std::sort), compact
*/

#define RESET	"\033[0m"
#define GREEN	"\033[1;32m"
#define YELLOW	"\033[1;38;5;220m"
#define ORANGE	"\033[1;38;5;208m"
#define RED		"\033[31;1m"
#define CYAN	"\033[36;1m"
#define MGT		"\033[1;35m"
#define BLINK	"\e[5m"

#endif