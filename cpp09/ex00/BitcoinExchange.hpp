#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <climits>
#include <cstdlib>
#include <cctype>

class BitcoinExchange {
public:
    BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

	void loadRates(const std::string& filename);
    void parseInput(const std::string& input);
	double getRate(const std::string& date);
	bool isValidDate(const std::string& date);
	bool isValidValue(double value, const std::string& valueStr);

private:
	std::map<std::string, double> _rates;
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