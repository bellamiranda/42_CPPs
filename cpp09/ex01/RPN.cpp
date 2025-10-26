#include "RPN.hpp"

std::stack<double> RPN::_stack;

RPN::RPN() {}

RPN::RPN(const RPN& other) {
	(void)other;
}

RPN& RPN::operator=(const RPN& other) {
	(void)other;
	return *this;
}

RPN::~RPN() {}

static bool isValidOperator(char op) {
	if (op == '+' || op == '-' || op == '*' || op == '/')
		return true;
	return false;
}

static void checkNotation(std::string expression) {
	for (unsigned int i = 0; i < expression.length(); i++) {
		if (std::isdigit(expression[i]) == 0)
			if (!isValidOperator(expression[i]))
				if (!std::isspace(expression[i]))
					throw (std::invalid_argument("Error"));
		if ((std::isdigit(expression[i]) || isValidOperator(expression[i]))
		&& expression[i + 1] && std::isspace(expression[i + 1]) == 0)
			throw (std::invalid_argument("Error"));
	}
}

void RPN::process(const std::string& expression) {
    checkNotation(expression);
    for (unsigned int i = 0; i < expression.length(); i++) {
        if (std::isdigit(expression[i]))
            _stack.push(expression[i] - 48);
		if (isValidOperator(expression[i]) && _stack.size() < 2)
			throw (std::invalid_argument("Error"));
        if (_stack.size() >= 2 && isValidOperator(expression[i])) 
			RPN::calculate(expression[i]);
    }
    if (_stack.size() == 1)
        std::cout << _stack.top() << std::endl;
    else 
        std::cout << RED << "Error: This is not Polish Notation format" << RESET << std::endl;
}

void RPN::calculate(char op) {
    double first_number;
    double second_number;
    double result;

    first_number = _stack.top();
    _stack.pop();
    second_number = _stack.top();
    _stack.pop();
    switch (op) {
		case '+':
			result = second_number + first_number;	
			break;
		case '-':
			result = second_number - first_number;	
			break;
		case '*':
			result = second_number * first_number;	
			break;
		case '/':
			if (first_number == 0) 
                throw (std::invalid_argument("Error: Division by Zero"));				
			result = second_number / first_number;	
			break;
    }
    if (result > std::numeric_limits<int>::max())
        throw (std::invalid_argument("Error: Division by Zero"));
    else
        _stack.push(result);
}
