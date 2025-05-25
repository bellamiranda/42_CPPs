#include "Form.hpp"

int main(void){
    std::cout << " ---- BASIC SIGN FORM TEST ---- " << std::endl;
    try {
        Bureaucrat bob("Bob", 50);
        Bureaucrat alice("Alice", 25);
        Form taxForm("TaxForm", 30, 20);
        alice.signForm(taxForm); //works normally
        bob.signForm(taxForm); //grade too low

    } catch (std::exception &e) {
        std::cerr << MGT <<"EXCEPTION CAUGHT: " << e.what() << RESET << std::endl;
    }

    std::cout << "\n ---- GRADE TOO HIGH TO CREATE BUREAUCRAT ---- " << std::endl;
    try {
        Bureaucrat high("High", 0); //cannot be created with grade 0
    } catch (std::exception &e) {
        std::cerr << MGT <<"EXCEPTION CAUGHT: " << e.what() << RESET << std::endl;
    }

    std::cout << "\n ---- GRADE TOO LOW TO CREATE A BUREAUCRAT ---- " << std::endl;
    try {
        Bureaucrat low("Low", 151);//cannot be created
    } catch (std::exception &e) {
        std::cerr << MGT <<"EXCEPTION CAUGHT: " << e.what() << RESET << std::endl;
    }

    std::cout << "\n ---- ALREADY SIGNED FORM ---- " << std::endl;
    try {
        Bureaucrat carla("Carla", 10);
        Form passportForm("PassportForm", 20, 15);

        carla.signForm(passportForm); //works normally
        carla.signForm(passportForm); //is already signed
    } catch (std::exception &e) {
        std::cerr << MGT <<"EXCEPTION CAUGHT: " << e.what() << RESET << std::endl;
    }

    return 0;
}
