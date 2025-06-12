#include "AForm.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _gradeSign(150), _gradeExecute(150) {}

AForm::AForm(std::string name, int gradeSign, int gradeExecute) : _name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute) {
	if (this->_gradeSign < 1 || this->_gradeExecute < 1)
		throw AForm::GradeTooHighException();
	else if (this->_gradeSign > 150 || this->_gradeExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& src) : _name(src._name), _isSigned(src._isSigned), _gradeSign(src._gradeSign), _gradeExecute(src._gradeExecute) {}

AForm& AForm::operator=(const AForm& src) {
	if (this != &src) 
		this->_isSigned = src._isSigned;
	return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const {
	return this->_name;
}

bool AForm::getSigned() const {
	return this->_isSigned;
}

int AForm::getGradeSign() const {
	return this->_gradeSign;
}

int AForm::getGradeExecute() const {
	return this->_gradeExecute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeSign)
		throw AForm::GradeTooLowException();
	if (this->_isSigned)
		throw AForm::FormIsSignedException();
	this->_isSigned = true;
	//std::cout << GREEN << bureaucrat.getName() << " signed " << this->_name << RESET << std::endl;
}

void AForm::checkExecutionRequirements(Bureaucrat const& executor) const {
	if (!this->_isSigned)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->_gradeExecute)
		throw AForm::GradeTooLowException();
}

std::ostream &operator<<(std::ostream& buf, const AForm& form) {
	buf << MGT << "Form: " << form.getName() << "\nGrade to Sign: " << form.getGradeSign() << "\nGrade to Execute: " << form.getGradeExecute() << "\nIs signed? " << RESET;
	if (form.getSigned())
		buf << GREEN << " YES" << RESET;
	else
		buf << RED << " NO" << RESET;
	return buf;
}