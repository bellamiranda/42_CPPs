#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45), _target("Default") {
	//std::cout << GREEN << "RobotomyRequestForm created with target " << this->_target << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45), _target(target) {
	//std::cout << GREEN << "RobotomyRequestForm created with target " << this->_target << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src), _target(src._target) {
	//std::cout << GREEN << "RobotomyRequestForm copy created with target " << this->_target << RESET << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src) {
	if (this != &src) {
		AForm::operator=(src);
		this->_target = src._target;
	}
	return *this;
}

std::string RobotomyRequestForm::getTarget() const {
	return this->_target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	this->checkExecutionRequirements(executor);
	std::cout << YELLOW BLINK << "Bzzzzzz... " << 
	"\n      ...Bzzzzzz...    " << RESET << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << YELLOW << this->_target << " has been robotomized successfully!" << RESET << std::endl;
	else
		std::cout << RED << "Robotomy failed for " << this->_target << "!" << RESET << std::endl;
}