#pragma once
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <math.h>
#include <limits>

template <typename T>
class Array {
private:
	T* _data;
	unsigned int _size;//std::size_t
public:
	Array() : _data(NULL), _size(0) {} //value-initialized to NULL and size to 0
	Array(unsigned int n) : _data(new T[n]()), _size(n) {}
	Array(const Array& src) : _data(NULL), _size(src._size) {
		if (_size > 0) {
			_data = new T[_size];
			for (unsigned int i = 0; i < _size; ++i)
				_data[i] = src._data[i];
		}
	}
	Array& operator=(const Array& src) {
		if (this != &src) {
			delete[] _data;
			_size = src._size;
			if (_size > 0) {
				_data = new T[_size];
				for (unsigned int i = 0; i < _size; ++i)
					_data[i] = src._data[i];
			} else
				_data = NULL;
		}
		return *this;
	}
	T& operator[](unsigned int index) {
		if (index >= _size)
			throw std::out_of_range("Index out of range");
		return _data[index];
	}
	//ensure const correctness
	const T& operator[](unsigned int index) const {
		if (index >= _size)
			throw std::out_of_range("Index out of range");
		return _data[index];
	}
	~Array() {
		delete[] _data;
	}
	unsigned int size() const {
		return _size;
	}
};

#define INT_MAX		std::numeric_limits<int>::max()
#define INT_MIN		std::numeric_limits<int>::min()

#define RESET	"\033[0m"
#define GREEN	"\033[1;32m"
#define YELLOW	"\033[1;38;5;220m"
#define ORANGE	"\033[1;38;5;208m"
#define RED		"\033[31;1m"
#define CYAN	"\033[36;1m"
#define MGT		"\033[1;35m"
#define BLINK	"\e[5m"

#endif