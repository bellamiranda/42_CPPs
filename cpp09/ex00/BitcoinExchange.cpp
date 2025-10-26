#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other)
		this->rates = other.rates;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadRates(const std::string& filename) {
	std::ifstream file(filename.c_str());
    if (!file) {
        std::cerr << RED << "Error: could not open data file." << RESET << std::endl;
        exit(1);
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        size_t sep = line.find(',');
        if (sep == std::string::npos)
            continue;

        std::string date = line.substr(0, sep);
        double rate = std::atof(line.substr(sep + 1).c_str());
        rates[date] = rate;
    }
}

void BitcoinExchange::parseInput(const std::string& input) {
	std::ifstream file(input.c_str());
	if (!file) {
		std::cerr << RED << "Error: could not open input file." << RESET << std::endl;
		exit(1);
	}

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line)) {
		if (line.empty())
			continue;
		size_t sep = line.find(" | ");
		if (sep == std::string::npos) {
			std::cerr << RED << "Error: bad input => " << line << RESET << std::endl;
			continue;
		}
		std::string date = line.substr(0, sep);
		std::string valueStr = line.substr(sep + 3);

		double value = atof(valueStr.c_str());
		if (!isValidDate(date) || !isValidValue(value, valueStr))
			continue;

		double rate = getRate(date);
		std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
	}
}

double BitcoinExchange::getRate(const std::string& date) {
	std::map<std::string, double>::const_iterator it = rates.lower_bound(date);
	if (it != rates.end() && it->first == date)
		return it->second;
	if (it == rates.begin())
		return 0.0;
	--it;
	return it->second;
}

bool BitcoinExchange::isValidDate(const std::string& date) {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
		std::cerr << RED << "Error: invalid date format => " << date << RESET << std::endl;
		return false;
	}

	int year, month, day;
	char sep1, sep2;
	std::istringstream iss(date);
	if (!(iss >> year >> sep1 >> month >> sep2 >> day)) {
		std::cerr << RED << "Error: invalid date format => " << date << RESET << std::endl;
		return false;
	}

	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		daysInMonth[1] = 29;

	if (day > daysInMonth[month - 1] || sep1 != '-' || sep2 != '-' || month < 1 || month > 12 || day < 1 || year < 0) {
		std::cerr << RED << "Error: invalid date format => " << date << RESET << std::endl;
		return false;
	}

	return true;
}

bool BitcoinExchange::isValidValue(double value, const std::string& valueStr) {
	if (value < 0) {
		std::cerr << RED << "Error: not a positive number." << RESET << std::endl;
		return false;
	}
	if (value > 1000) {
		std::cerr << RED << "Error: too large a number." << RESET << std::endl;
		return false;
	}
	if (valueStr.empty()) {
		std::cerr << RED << "Error: not a number." << RESET << std::endl;
		return false;
	}

	bool hasDot = false;
	for (size_t i = 0; i < valueStr.length(); ++i) {
	char c = valueStr[i];

	if (c == '-') {
		if (i != 0) { // '-' can only be in pos 1
			std::cerr << RED << "Error: invalid minus sign." << RESET << std::endl;
			return false;
		}
	}
	else if (c == '.') {
		if (hasDot) { // can only have one .
			std::cerr << RED << "Error: multiple dots." << RESET << std::endl;
			return false;
		}
		hasDot = true;
	}
	else if (!std::isdigit(c)) {
		std::cerr << RED << "Error: not a number." << RESET << std::endl;
		return false;
	}
	}
	return true;
}