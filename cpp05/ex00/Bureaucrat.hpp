#pragma once
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat {
protected:
	std::string const _name;
	int _grade;
public:
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();

	std::string getName() const;
	int getGrade() const;

	void increment();
	void decrement();


	class GradeTooHighException : public std::exception {
	public:
		const char *what() const throw() {
			return "Grade too high!";
		}
	};

	class GradeTooLowException : public std::exception {
	public:
		const char *what() const throw() {
			return "Grade too low!";
		}
	};
};

std::ostream &operator<<(std::ostream& buf, const Bureaucrat& bureaucrat);

#define RESET	"\033[0m"
#define GREEN	"\033[1;32m"
#define YELLOW	"\033[1;38;5;220m"
#define ORANGE	"\033[1;38;5;208m"
#define RED		"\033[31;1m"
#define CYAN	"\033[36;1m"
#define MGT		"\033[1;35m"
#define BLINK	"\e[5m"

#endif