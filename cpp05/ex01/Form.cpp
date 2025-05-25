#include "Form.hpp"

Form::Form() : _name("Default"), _isSigned(false), _gradeSign(150), _gradeExecute(150) {}

Form::Form(std::string name, int gradeSign, int gradeExecute) : _name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute) {
	if (this->_gradeSign < 1 || this->_gradeExecute < 1)
		throw Form::GradeTooHighException();
	else if (this->_gradeSign > 150 || this->_gradeExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& src) : _name(src._name), _isSigned(src._isSigned), _gradeSign(src._gradeSign), _gradeExecute(src._gradeExecute) {}

Form& Form::operator=(const Form& src) {
	if (this != &src) 
		this->_isSigned = src._isSigned;
	return *this;
}

Form::~Form() {}

std::string Form::getName() const {
	return this->_name;
}

bool Form::getSigned() const {
	return this->_isSigned;
}

int Form::getGradeSign() const {
	return this->_gradeSign;
}

int Form::getGradeExecute() const {
	return this->_gradeExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeSign)
		throw Form::GradeTooLowException();
	if (this->_isSigned)
		throw Form::FormIsSignedException();
	this->_isSigned = true;
	//std::cout << GREEN << bureaucrat.getName() << " signed " << this->_name << RESET << std::endl;
}

std::ostream &operator<<(std::ostream& buf, const Form& form) {
	buf << MGT << "Form: " << form.getName() << "\nGrade to Sign: " << form.getGradeSign() << "\nGrade to Execute: " << form.getGradeExecute() << "\nIs signed? " << RESET;
	if (form.getSigned())
		buf << GREEN << " YES" << RESET;
	else
		buf << RED << " NO" << RESET;
	return buf;
}