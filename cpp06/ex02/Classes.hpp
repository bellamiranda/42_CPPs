#pragma once
#ifndef CLASSES_HPP
#define CLASSES_HPP

#include <iostream>
#include <string>
#include <math.h>

class Base {
public:
	virtual ~Base() {};
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

/* 
dynamic_cast<type>(data) downcasts a pointer or reference to its derived type
returns nullptr if the cast fails for pointers
throws std::bad_cast for references
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