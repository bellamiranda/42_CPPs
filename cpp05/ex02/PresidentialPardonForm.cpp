#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5), _target("Default") {
	//std::cout << GREEN << "Presidential Pardon Form created for target: " << this->_target << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5), _target(target) {
	//std::cout << GREEN << "Presidential Pardon Form created for target: " << this->_target << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm(src), _target(src._target) {
	//std::cout << GREEN << "Presidential Pardon Form copy created for target: " << this->_target << RESET << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src) {
	if (this != &src) {
		AForm::operator=(src);
		this->_target = src._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	//std::cout << RED << "Presidential Pardon Form for target " << this->_target << " destroyed" << RESET << std::endl;
}

std::string PresidentialPardonForm::getTarget() const {
	return this->_target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	this->checkExecutionRequirements(executor);
	std::cout << MGT << this->_target << " has been pardoned by Zaphod Beeblebrox" << RESET << std::endl;
}