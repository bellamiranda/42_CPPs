#pragma once
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <exception>
#include <vector>
#include <list>
#include <deque>

//find the first occurance of 'value' in the container 'T'
template <typename T>
typename T::iterator easyfind(T &container, int value) {
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::runtime_error("Value not found!");
	return it;
}

/* 
CONTAINER: data structor to store and manage objects
	sequence [i]: vector, list, deque, array (stores in linear order)
		vector - dynamic array, fast access, dynamic resizing
		deque - double ended queue, fast insertion and removal at both ends
		list - double linked list, fast insert and delete anywhere, slow access (list[i] doesn't exist)
	associative [key]: set (stores unique values), map (stores pairs), multiset, multimap
		keep elements sorted; key-based access (not by index - map[key]=25)
iterator -> data type that points to an element in the container
	it can be used to access the element and modify it if needed
std::find -> finds the first occurrence of value in the container
		if not found, it returns the end iterator of the container
		if found, it returns the iterator pointing to the found element
push_back(value) -> add element to end
insert(pos, value) -> insert at position
erase(pos) -> remove element
size() -> get number of elements
begin(), end() -> get iterators
find() -> search for a value
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