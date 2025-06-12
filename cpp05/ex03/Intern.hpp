#pragma once
#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

class Intern {
public:
	Intern();
	Intern(const Intern &src);
	Intern &operator=(const Intern &src);
	~Intern();

	AForm *makeShrubberyCreationForm(const std::string target);
	AForm *makeRobotomyRequestForm(const std::string target);
	AForm *makePresidentialPardonForm(const std::string target);
	AForm *makeForm(const std::string formName, const std::string target);
	class FormNotFoundException : public std::exception {
	public:
		const char *what() const throw() {
			return "Intern: Form not found";
		}
	};
};

#endif