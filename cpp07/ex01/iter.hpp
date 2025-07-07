#pragma once
#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T>
void print(const T& value) {
	std::cout << value << std::endl;
}

template <typename T, typename F>
void iter (T* array, int len, F f) {
	for (int i = 0; i < len; ++i)
		f(array[i]);
}

/* 
Template is a feature that allows you to write a 
generic code or class that will work with any data type
Increases code reusability and flexibility
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