#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <cstdlib>
#include <exception>
#include <limits>

class RPN {
public:
	RPN();
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	~RPN();

	void process(const std::string& expression);
	void calculate(char op);
private:
	static std::stack<double> _stack;
};


#define RESET	"\033[0m"
#define GREEN	"\033[1;32m"
#define YELLOW	"\033[1;38;5;220m"
#define ORANGE	"\033[1;38;5;208m"
#define RED		"\033[31;1m"
#define CYAN	"\033[36;1m"
#define MGT		"\033[1;35m"
#define BLINK	"\e[5m"

#endif