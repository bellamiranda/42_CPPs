#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << GREEN << "Bureaucrat " << this->_name << " created with grade " << this->_grade << RESET << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << RED << "Bureaucrat " << this->_name << " destroyed" << RESET << std::endl;
}

std::string Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::increment() {
	if (this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
	std::cout << CYAN << "Bureaucrat " << this->_name << " incremented to grade " << this->_grade << RESET << std::endl;
}

void Bureaucrat::decrement() {
	if (this->_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
	std::cout << CYAN << "Bureaucrat " << this->_name << " decremented to grade " << this->_grade << RESET << std::endl;
}

std::ostream &operator<<(std::ostream& buf, const Bureaucrat& bureaucrat) {
	buf << YELLOW << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << RESET;
	return buf;
}
