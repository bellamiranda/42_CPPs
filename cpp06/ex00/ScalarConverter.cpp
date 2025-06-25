#include "ScalarConverter.hpp"

//std::fixed - activate fixed-point notation (not scientific)
//std::setprecision(1) - defines the number of decimals
void ScalarConverter::ifChar(char c) {
	std::cout << MGT "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << std::fixed << std::setprecision(1) <<
	"float: " << static_cast<float>(c) << "f\n" <<
	"double: " << static_cast<double>(c) << RESET << std::endl;
}

void ScalarConverter::ifInt(const int i) {
	std::cout << ORANGE "char: ";
	if (i < 0 || i > 127 || !isprint(i)) {
		std::cout << "impossible" << std::endl;
	} else {
		std::cout << static_cast<char>(i) << std::endl;
	}
	std::cout << "int: " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1) <<
	"float: " << static_cast<float>(i) << "f\n" <<
	"double: " << static_cast<double>(i) << RESET << std::endl;
}

void ScalarConverter::ifFloat(const float f) {
	std::cout << CYAN "char: ";
	if (f < 0 || f > 127 || !isprint(static_cast<int>(f))) {
		std::cout << "impossible" << std::endl;
	} else {
		std::cout << static_cast<char>(f) << std::endl;
	}
	if (f < INT_MIN || f > INT_MAX) {
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	}
	std::cout << std::fixed << std::setprecision(1) <<
	"float: " << f << "f\n" <<
	"double: " << static_cast<double>(f) << RESET << std::endl;
}

//isnan - checks if the value is NaN (not a number)
//isinf - checks if the value is infinite
void ScalarConverter::ifDouble(const double d) {
	std::cout << YELLOW "char: ";
	if (d < 0 || d > 127 || !isprint(static_cast<int>(d))) {
		std::cout << "impossible" << std::endl;
	} else {
		std::cout << static_cast<char>(d) << std::endl;
	}
	if (d < INT_MIN || d > INT_MAX) {
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	}
	std::cout << std::fixed << std::setprecision(1);
	if ((d >= FLOAT_MIN && d <= FLOAT_MAX) || std::isnan(d) || std::isinf(d)) {
		std::cout << "float: " << static_cast<float>(d) << "f\n";
	} else {
		std::cout << "float: impossible\n";
	}
	std::cout << "double: " << d << RESET << std::endl;
}

void ScalarConverter::convert(const std::string &literal) {
	//empty
	if (literal.empty())
		throw ConversionError();

	//char
	if (literal.length() == 1 && isprint(literal[0]) && !isdigit(literal[0]))
		return ifChar(literal[0]);

	//int
	char *rest;
	long i = std::strtol(literal.c_str(), &rest, 10);
	//if it doesnt have . or - or any rest
	if (literal.find('.') == std::string::npos && !rest[0] && *literal.c_str() != '-')
		return ifInt(i);//std::atoi(literal.c_str()) or static_cast<int>(i));

	//float
	float f = std::strtof(literal.c_str(), &rest);
	if ((rest[0] == 'f' && !rest[1]) || literal == "nanf" || literal == "+inff" || literal == "-inff")
		return ifFloat(f);//std::atof(literal.c_str());

	//double
	double d = std::strtod(literal.c_str(), &rest);
	if (*rest == '\0' || literal == "nan" || literal == "+inf" || literal == "-inf") {
		if (literal.find('f') != std::string::npos)
			return ifFloat(static_cast<float>(d));//PRECISO DISSO?
		return ifDouble(d);//std::strtod(literal.c_str(), NULL);
	}

	std::cerr << RED "Error: Invalid literal '" << literal << "'" RESET << std::endl;
}
//strtol - converts a string to a long
//strtof - converts a string to a float
//strtod - converts a string to a double
//double (8 bytes) is more precise than float (4 bytes)