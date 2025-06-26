#pragma once
#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h> //uintptr_t

typedef struct Data {
	int id;
	std::string name;
} Data;

class Serializer {
private:
	Serializer() {};
	~Serializer() {};
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

/*
uintptr_t is an int that can store a pointer without loosing data
reinterpret_cast<type>(data) converters any type to any other type
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