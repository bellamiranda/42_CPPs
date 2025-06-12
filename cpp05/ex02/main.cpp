#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void){
	std::srand(std::time(NULL)); //initialize time for random in the Robotomy
	Bureaucrat bureaucrat("John", 1);
	ShrubberyCreationForm shrubbery("Home");
	bureaucrat.executeForm(shrubbery); // Try executing before signing
	bureaucrat.signForm(shrubbery);
	bureaucrat.executeForm(shrubbery);
	RobotomyRequestForm robotomy("Robot");
	bureaucrat.executeForm(robotomy);
	bureaucrat.signForm(robotomy);
	bureaucrat.executeForm(robotomy); //Try to execute a lot to check random
	bureaucrat.executeForm(robotomy);
	bureaucrat.executeForm(robotomy);
	PresidentialPardonForm presidential("President");
	bureaucrat.executeForm(presidential);
	bureaucrat.signForm(presidential);
	bureaucrat.executeForm(presidential);
	std::cout << std::endl;
	Bureaucrat lowGradeBureaucrat("LowGrade", 150);
	try {
		lowGradeBureaucrat.executeForm(shrubbery);
		ShrubberyCreationForm lowGradeShrubbery("LowGradeHome");
		lowGradeBureaucrat.signForm(lowGradeShrubbery);
		lowGradeBureaucrat.executeForm(lowGradeShrubbery);
	} catch (std::exception& e) {
		std::cout << RED << "Error: " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
	try {
		lowGradeBureaucrat.executeForm(robotomy);
		RobotomyRequestForm lowGradeRobotomy("LowGradeRobot");
		lowGradeBureaucrat.signForm(lowGradeRobotomy);
		lowGradeBureaucrat.executeForm(lowGradeRobotomy);
	} catch (std::exception& e) {
		std::cout << RED << "Error: " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
	try {
		lowGradeBureaucrat.executeForm(presidential);
		PresidentialPardonForm lowGradePresidential("LowGradePresident");
		lowGradeBureaucrat.signForm(lowGradePresidential);
		lowGradeBureaucrat.executeForm(lowGradePresidential);
	} catch (std::exception& e) {
		std::cout << RED << "Error: " << e.what() << RESET << std::endl;
	}
	return 0;
}
