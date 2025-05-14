#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	//std::cout << "MateriaSource Default constructor" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_source[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& src){
	//std::cout << "MateriaSource Copy constructor" << std::endl;
	this->copySource(src);
}

MateriaSource& MateriaSource::operator=(const MateriaSource& src){
	if (this != &src){
		//std::cout << "MateriaSource assignment operator" << std::endl;
		this->copySource(src);
	}
	return *this;
}

MateriaSource::~MateriaSource(){
	//std::cout << "MateriaSource Destructor" << std::endl;
	int i = 0;
	while (this->_source[i])
		delete (this->_source[i++]);
}

void MateriaSource::learnMateria(AMateria* m){
	int i = 0;
	while (this->_source[i])
		i++;
	if (i == 3)
		std::cout << RED "MateriaSource is full!! Cannot learn one more" RESET << std::endl;
	else {
		std::cout << GREEN "New Materia " << m->getType() << " learned!" RESET << std::endl;
		this->_source[i] = m;
	}
}

//create copies of learned materias to be equiped by character
//verify backwards to priorize the last one learned
AMateria* MateriaSource::createMateria(std::string const & type){
	int i = 0;
	while (this->_source[i])
		i++;
	i--;
	while (this->_source[i]) {
		if (this->_source[i]->getType() == type) {
			std::cout << GREEN "Creating " << type << " materia" RESET << std::endl;
			return (this->_source[i]->clone());
		}
		i--;
	}
	std::cout << RED "Unknown type! No Materia created!" RESET << std::endl;
	return 0;
}

void MateriaSource::copySource(const MateriaSource& src){
	for (int i = 0; i < 4; i++){
/* 		if (this->_source[i])
			delete (this->_source[i]); */
		//this->_source[i] = src._source[i] ? src._source[i]->clone() : NULL;
		this->_source[i] = NULL;
		if (src._source[i])
			this->_source[i] = src._source[i]->clone();
	}
}
