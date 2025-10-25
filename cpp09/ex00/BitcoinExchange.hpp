#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>

class BitcoinExchange {
public:
    BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void parseInput(const std::string& input);
    void calculateExchange(const std::string& date, double amount);

private:
	std::map<std::string, double> exchangeRates;

	void loadExchangeRates(const std::string& filename);
	bool isValidDate(const std::string& date);
	bool isValidAmount(double amount);
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