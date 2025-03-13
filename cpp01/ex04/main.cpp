#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#define GREEN	"\e[0;32m"
#define MGT		"\033[1;35m"
#define RED		"\e[0;31m"
#define CYAN	"\e[1;36m"
#define RESET	"\e[0m"

void replace(std::ofstream& output_file, std::ifstream& input_file, char **argv)
{
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::string line;
	size_t i = 0;
    while (std::getline(input_file, line)){
        i = 0;
        i = line.find(s1, i);//if s1 is not found, find() returns std::string::npos
		while (i != std::string::npos){
            line.erase(i, s1.length());
            line.insert(i, s2);
            i += s2.length();
			i = line.find(s1, i);
        }
        output_file << line << std::endl;
    }
}

int	main(int argc, char **argv)
{
	if (argc != 4){
		std::cout << RED << "Invalid input!!\nPlease enter <filename> <oldstr> <newstr>" << RESET << std::endl;
		return (EXIT_FAILURE);
	}
	std::ifstream input_file;
	input_file.open((const char *)argv[1]);
	if (!input_file.is_open()){
		std::cout << RED << "Error trying to open Input file" << RESET << std::endl;
		return (EXIT_FAILURE);
	}
	std::ofstream output_file;
	output_file.open((std::string(argv[1]).append(".replace")).c_str());
	if (!output_file.is_open()){
		std::cout << RED << "Error trying to open Output file" << RESET << std::endl;
		return (EXIT_FAILURE);
	}
	replace(output_file, input_file, argv);
	return (EXIT_SUCCESS);
}

/* 
std::ifstream inFile("filename") -> read from a file
std::ofstream outFile("filename") -> creates and writes to a file
std::fstream -> can be used for reading and writing
npos -> indicates that a substring search has failed (largest possible value of size_t)

content.find(s1, pos) -> finds the ocuurence of s1 starting from i
content.substr(0, pos) -> extracts everythinh before s1
content.substr(pos + s1.lenght()) -> extracts everything after s1
content = newString -> creates a new string with the replaced text
outFile << content -> writes the content to a file
outFile.close() -> closes the file properly
 */