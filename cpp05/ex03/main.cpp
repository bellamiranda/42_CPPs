#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void){
	std::srand(std::time(NULL)); //initialize time for random in the Robotomy
	Bureaucrat bureaucrat("John", 1);
	Intern intern;
	AForm *form1;
	try {
		form1 = intern.makeForm("shrubbery creation", "home");
		bureaucrat.signForm(*form1);
		bureaucrat.executeForm(*form1);
	} catch (std::exception &e) {
		std::cerr << RED << "EXCEPTION CAUGHT: " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
	
	AForm *form2;
	try {
		form2 = intern.makeForm("robotomy request", "robot");
		bureaucrat.signForm(*form2);
		bureaucrat.executeForm(*form2);
	}
	catch (std::exception &e) {
		std::cerr << RED << "EXCEPTION CAUGHT: " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	AForm *form3;
	try {
		form3 = intern.makeForm("presidential pardon", "presidential");
		bureaucrat.signForm(*form3);
		bureaucrat.executeForm(*form3);
	}
	catch (std::exception &e) {
		std::cerr << RED << "EXCEPTION CAUGHT: " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	AForm *form4;
	try {
		form4 = intern.makeForm("non existing", "try");
		bureaucrat.signForm(*form4);
		bureaucrat.executeForm(*form4);
	}
	catch (std::exception &e) {
		std::cerr << RED << "EXCEPTION CAUGHT: " << e.what() << RESET << std::endl;
	}
	
	delete form1; delete form2; delete form3;
	return 0;
}
