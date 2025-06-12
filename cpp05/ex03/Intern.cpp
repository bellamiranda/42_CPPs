#include "Intern.hpp"

Intern::Intern() {
	//std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &src) {
	(void)src;
	//std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &src) {
	if (this == &src) {
		(void)src;
		//std::cout << "Intern assignment operator called" << std::endl;
	}
	return *this;
}

Intern::~Intern() {
	//std::cout << "Intern destructor called" << std::endl;
}

AForm *Intern::makeShrubberyCreationForm(const std::string target) {
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobotomyRequestForm(const std::string target) {
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makePresidentialPardonForm(const std::string target) {
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(const std::string formName, const std::string target) {

	std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *(Intern::*memberFunctions[3])(std::string target) = {
		&Intern::makeShrubberyCreationForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm};

	for (int i = 0; i < 3; i++) {
		if (formName == formNames[i]) {
			std::cout << GREEN << "Intern creates " << formName << RESET << std::endl;
			return ((this->*memberFunctions[i])(target));
		}
	}
	throw Intern::FormNotFoundException();
}
