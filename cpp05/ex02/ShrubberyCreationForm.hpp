#pragma once
#ifndef SCFORM_HPP
#define SCFORM_HPP

#include "AForm.hpp"
#include <fstream> //std::ofstream

class ShrubberyCreationForm : public AForm {
private:
	std::string _target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm&);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);
	~ShrubberyCreationForm();

	std::string getTarget() const;
	void execute(Bureaucrat const & executor) const;
};

#endif