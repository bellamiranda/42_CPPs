#pragma once
#ifndef RRFORM_HPP
#define RRFORM_HPP

#include "AForm.hpp"
#include <cstdlib> //rand()
#include <ctime>   //time()

class RobotomyRequestForm : public AForm {
private:
	std::string _target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& src);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& src);

	std::string getTarget() const;
	void execute(Bureaucrat const & executor) const;
};

#endif