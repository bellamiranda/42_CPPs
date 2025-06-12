#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default") {
	//std::cout << GREEN << "ShrubberyCreationForm created with target " << this->_target << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137), _target(target) {
	//std::cout << GREEN << "ShrubberyCreationForm created with target " << this->_target << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(src), _target(src._target) {
	//std::cout << GREEN << "ShrubberyCreationForm copy created with target " << this->_target << RESET << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src) {
	if (this != &src) {
		AForm::operator=(src);
		this->_target = src._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	//std::cout << RED << "ShrubberyCreationForm with target " << this->_target << " destroyed" << RESET << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const {
	return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	this->checkExecutionRequirements(executor);
	std::ofstream ofs(this->getTarget().append("_shrubbery").c_str());
	if (!ofs.is_open())
		throw std::ios_base::failure("Failed to open file on Shrubbery");//ofstream exception
	ofs << "        _-_-_\n";
	ofs << "      /       \\\n";
	ofs << "     /         \\\n";
	ofs << "    /           \\\n";
	ofs << "   /             \\\n";
	ofs << "  /_______________\\\n";
	ofs << "        | | |\n";
	ofs.close();
}