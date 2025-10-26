#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << RED << "Error: could not open file." << RESET << std::endl;
		return 1;
	}

	BitcoinExchange btc;
	btc.loadRates("data.csv");
	btc.parseInput(argv[1]);

	return 0;
}