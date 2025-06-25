#pragma once
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cmath>
#include <string>
#include <limits>
#include <iomanip>//setprecision
#include <cstdlib>

class ScalarConverter {
private:
	ScalarConverter() {}; //private constructor to prevent instantiation
	ScalarConverter(const ScalarConverter &src) {*this = src;};
	ScalarConverter &operator=(const ScalarConverter &other) {
		(void)other;
		return *this;
	};
	~ScalarConverter() {};

	static void ifChar(char c);
	static void ifInt(const int i);
	static void ifFloat(const float f);
	static void ifDouble(const double d);
public:
	static void convert(const std::string &literal);
	class ConversionError : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Conversion Error: Invalid literal";
		}
	};
};

/* static methods can be called without an instance of the class
and cannot access atributes or methods that are not static
Class::method() is the practical way to access it

(for downcasting -> converting to a smaller type)
static_cast<type>(value) -> explicit convertion (at compile time)
dynamic_cast<type>(value) -> runtime conversion (for polymorphism)
	only for inheritance and has to be checked if (value != NULL)
	if pointer -> dynamic_cast<type>(value) -> safe downcasting
	if reference -> dynamic_cast<type&>(*value) -> throws std::bad_cast if fails
reinterpret_cast<type>(value) -> low-level cast (no type checking)
	works for any pointer, for upcast and downcast
const_cast<type>(value) -> cast away consts (not recommended)
KEYWORDS -> operator (overloading);
	explicit (prevents implicit conversion);
	virtual (allows polymorphism);
 */


#define INT_MAX		std::numeric_limits<int>::max()
#define INT_MIN		std::numeric_limits<int>::min()
#define FLOAT_MAX	std::numeric_limits<float>::max()
#define FLOAT_MIN	-std::numeric_limits<float>::max()
//#define FLOAT_MIN	std::numeric_limits<float>::min() //represents the smallest positive
#define DOUBLE_MAX	std::numeric_limits<double>::max()
#define DOUBLE_MIN	-std::numeric_limits<double>::max()

#define RESET	"\033[0m"
#define GREEN	"\033[1;32m"
#define YELLOW	"\033[1;38;5;220m"
#define ORANGE	"\033[1;38;5;208m"
#define RED		"\033[31;1m"
#define CYAN	"\033[36;1m"
#define MGT		"\033[1;35m"
#define BLINK	"\e[5m"

#endif