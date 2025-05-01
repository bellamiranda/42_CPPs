#include "Brain.hpp"

Brain::Brain(){
	std::cout << YELLOW << "Brain Default constructor" << RESET << std::endl;
}

Brain::Brain(const Brain& copy){
	std::cout << YELLOW << "Brain Copy constructor" << RESET << std::endl;
	for (int i = 0; i < 100; ++i)
        _ideas[i] = copy._ideas[i];
}

Brain& Brain::operator=(const Brain& copy){
	if (this != &copy){
		std::cout << YELLOW << "Brain Copy assignment operator" << RESET << std::endl;
		for (int i = 0; i < 100; ++i)
        	_ideas[i] = copy._ideas[i];
	}
	return *this;
}

Brain::~Brain(){
	std::cout << YELLOW << "Brain Destructor" << RESET << std::endl;
}

void Brain::setIdea(const std::string newIdea){
	if (newIdea.empty()){
		std::cout << "Please insert a valid idea" << std::endl;
		return ;
	}

	int i = 0;
	while(i < 100 && !this->_ideas[i].empty()){
		i++;
	}
	if (i < 100){
		this->_ideas[i] = newIdea;
		std::cout << GREEN "New idea '" << newIdea << "' added to the brain in the position " << i << std::endl;
	}
	else
		std::cout << RED "Brain is FULL!! No space for new ideas.\n" RESET << std::endl;
}

std::string Brain::getIdea(int index) const{
//FACO RETORNANDO A ARRAY TODA OU SO O INDEX?????
	if (index >= 0 && index < 100)
		return this->_ideas[index];
	return "";
}