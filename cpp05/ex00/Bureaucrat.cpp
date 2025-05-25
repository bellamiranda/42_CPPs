#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
	std::cout << GREEN << "Bureaucrat " << this->_name << " created with grade " << this->_grade << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << GREEN << "Bureaucrat " << this->_name << " created with grade " << this->_grade << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name), _grade(src._grade) {
	std::cout << GREEN << "Bureaucrat " << this->_name << "copy created with grade " << this->_grade << RESET << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src) {
	if (this != &src) {
		//this->_name = src._name;
		this->_grade = src._grade;
	}
	return *this;
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
