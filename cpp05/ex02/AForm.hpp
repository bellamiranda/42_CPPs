#pragma once
#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm {
private:
	const std::string _name;
	bool _isSigned;
	const int _gradeSign;
	const int _gradeExecute;
public:
	AForm();
	AForm(std::string, int, int);
	AForm(const AForm&);
	AForm& operator=(const AForm&);
	virtual ~AForm();

	std::string getName() const;
	bool getSigned() const;
	int getGradeSign() const;
	int getGradeExecute() const;
	void beSigned(const Bureaucrat&);

	void checkExecutionRequirements(Bureaucrat const& executor) const;
	virtual void execute(Bureaucrat const & executor) const = 0;

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
	class FormNotSignedException : public std::exception {
	public:
		const char *what() const throw() {
			return "Form: Form is not signed - cannot execute!";
		}
	};
};

std::ostream &operator<<(std::ostream& buf, const AForm& form);

#endif