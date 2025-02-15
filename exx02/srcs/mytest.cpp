#include <iostream>
#include <iomanip>
#include <ctime>

/* int	main() {
	time_t timestamp = std::time(NULL);
	struct tm time = *std::localtime(&timestamp);

	std::cout << "[" << time.tm_year + 1900 <<
	std::setfill('0') << std::setw(2) << time.tm_mon + 1 <<
	std::setfill('0') << std::setw(2) << time.tm_mday << "_" <<
	std::setfill('0') << std::setw(2) << time.tm_hour <<
	std::setfill('0') << std::setw(2) << time.tm_min <<
	std::setfill('0') << std::setw(2) << time.tm_sec << "]";
} */