#pragma once
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>

template <typename T>
typename T::iterator easyfind(T &container, int value) {
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		std::cerr << RED << "[✖] Element not found" << RESET << std::endl;
	return it;
}

/* 
CONTAINER: data structor to store and manage objects
	sequence: vector, list, deque, array (stores in linear order)
	associative: set (stores unique values), map (stores key-value pairs), multiset, multimap
std::find -> finds the first occurrence of value in the container
	if not found, it returns the end iterator of the container
	if found, it returns the iterator pointing to the found element
iterator -> data type that points to an element in the container
	it can be used to access the element and modify it if needed
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