#include "Brain.hpp"

Brain::Brain(){
	std::cout << YELLOW << "Brain Default constructor" << RESET << std::endl;
}

Brain::Brain(const Brain& copy){
	std::cout << YELLOW << "Brain Copy constructor" << RESET << std::endl;
	this->copyIdeas(copy);
}

Brain& Brain::operator=(const Brain& copy){
	if (this != &copy){
		std::cout << YELLOW << "Brain Copy assignment operator" << RESET << std::endl;
		this->copyIdeas(copy);
		//copy each element of the array individually (content)
		//string manages its own heap memory -> deep copy
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
	while (i < 100 && !this->_ideas[i].empty()){
		i++;
	}
	if (i < 100){
		this->_ideas[i] = newIdea;
		std::cout << GREEN "New idea '" << newIdea << "' added to the brain in the position " << i + 1 << std::endl;
	}
	else
		std::cout << RED "Brain is FULL!! No space for new ideas." RESET << std::endl;
}

std::string *Brain::getIdeas(){
	return this->_ideas;
}

void Brain::displayIdeas(){
	if (this->_ideas[0].empty()){
		std::cout << RED "Brain is empty!! No idea to display" RESET << std::endl;
		return;
	}
	int i = -1;
	while (!this->_ideas[++i].empty())
		std::cout << TURQ << this->_ideas[i] << RESET << std::endl;
	return;
}

void Brain::copyIdeas(const Brain &src){
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = src._ideas[i];
}