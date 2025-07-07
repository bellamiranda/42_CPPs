#pragma once
#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>

template <typename T>
void swap(T &a, T &b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
const T& min(const T &a, const T &b) {
	return (a < b) ? a : b;
}

template <typename T>
const T& max(const T &a, const T &b) {
	return (a > b) ? a : b;
}

#define RESET	"\033[0m"
#define GREEN	"\033[1;32m"
#define YELLOW	"\033[1;38;5;220m"
#define ORANGE	"\033[1;38;5;208m"
#define RED		"\033[31;1m"
#define CYAN	"\033[36;1m"
#define MGT		"\033[1;35m"
#define BLINK	"\e[5m"

#endif