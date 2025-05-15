#include "Floor.hpp"

//initialize static instance (singleton)
Floor* Floor::_instance = NULL;

Floor::Floor(){
	this->_matAtFloor = NULL;
}

Floor::Floor(const Floor& src){
	(void)src;
	std::cout << RED "ERROR: Singleton cannot be copyed!!" RESET << std::endl;
}

Floor& Floor::operator=(const Floor&src) {
	(void) src;
	std::cout << RED "ERROR: Singleton cannot be copyed!!" RESET << std::endl;
	return (*this);
}

Floor::~Floor() {}

Floor* Floor::getInstance() {
	if (!_instance)
		_instance = new Floor();
	return _instance;
}

listOfMaterias* Floor::getMateriasAtFloor() const {
	return this->_matAtFloor;
}

void Floor::leaveMateriaAtFloor(AMateria* m){
	/* if (m->atFloor || !m->isEquiped){
		std::cout << RED << m->getType() << " is already at the floor" RESET << std::endl;
		return;
	} */
	if (!this->_matAtFloor){//if its empty
		this->_matAtFloor = new listOfMaterias;
		this->_matAtFloor->content = m;
		this->_matAtFloor->next = NULL;
	}
	else {
		listOfMaterias* temp = _matAtFloor;
		while (temp->next)
			temp = temp->next;
		temp->next = new listOfMaterias;
		temp->next->content = m;
		temp->next->next = NULL;
	}	
	m->isEquiped = false;
	m->atFloor = true;
}

void	Floor::removeMateria(AMateria *m){
	if (!m || !this->_matAtFloor)
		return;
	listOfMaterias *temp = this->_matAtFloor;
	listOfMaterias *toDelete = NULL;
	if (temp->content == m){//if its the first one
		this->_matAtFloor = temp->next;
		delete temp;
		return ;
	}
	while (temp->next) {
		if (temp->next->content == m) {
			toDelete = temp->next;
			temp->next = temp->next->next;
			delete toDelete;
			return ;
		}
		temp = temp->next;
	}
}

void Floor::cleanFloor() {
	listOfMaterias *temp;
	while (this->_matAtFloor) {
		temp = this->_matAtFloor;
		delete temp->content;
		this->_matAtFloor = this->_matAtFloor->next;
		delete temp;
	}
	delete this;
	_instance = NULL;
}

void	Floor::displayFloor(){
	listOfMaterias *temp;
	std::cout << CYAN "\nDISPLAYING MATERIAS AT FLOOR:" RESET << std::endl;
	int i = 1;
	temp = this->_matAtFloor;
	while (temp) {
		std::cout << CYAN << i << "-> " << temp->content->getType() << RESET << std::endl; 
		temp = temp->next;
		i++;
	}
}