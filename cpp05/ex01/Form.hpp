#pragma once
#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form {
private:
	const std::string _name;
	bool _isSigned;
	const int _gradeSign;
	const int _gradeExecute;
public:
	Form();
	Form(std::string, int, int);
	Form(const Form&);
	Form& operator=(const Form&);
	~Form();

	std::string getName() const;
	bool getSigned() const;
	int getGradeSign() const;
	int getGradeExecute() const;
	void beSigned(const Bureaucrat&);

	class GradeTooHighException : public std::exception {
	public:
		const char *what() const throw() {
			return "Form: Grade too high!";
		}
	};
	class GradeTooLowException : public std::exception {
	public:
		const char *what() const throw() {
			return "Form: Grade too low!";
		}
	};
	class FormIsSignedException : public std::exception {
	public:
		const char *what() const throw() {
			return "Form: Form is already signed!";
		}
	};
};

std::ostream &operator<<(std::ostream& buf, const Form& form);

#endif