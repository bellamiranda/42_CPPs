#include "Character.hpp"

Character::Character() {
	//std::cout << "Character Default constructor" << std::endl;
	for (int i = 0; i < 4; i++){
		this->_inventory[i] = NULL;
	}
}

Character::Character(std::string const & name) : _name(name) {
	//std::cout << "Character Parametrized constructor-> " << name << std::endl;
	for (int i = 0; i < 4; i++){
		this->_inventory[i] = NULL;
	}
}

Character::Character(const Character& copy) : _name(copy._name) {
	//std::cout << "Character Copy constructor called" << std::endl;
	this->copyInventory(copy);
}

Character& Character::operator=(const Character& copy){
	if (this != &copy){
		//std::cout << "Character assignment operator" << std::endl;
		this->_name = copy._name;
		this->copyInventory(copy);
	}
	return *this;
}

Character::~Character(){
	//std::cout << "Character destructor-> " << this->_name << std::endl;
	for (int i = 0; i < 4; ++i)
		if (this->_inventory[i])
			delete this->_inventory[i];
}


std::string const & Character::getName() const{
	return this->_name;
}

void Character::equip(AMateria* m){
	if (!m)
		return;
	if (m->isEquiped){
		std::cout << RED "The materia " << m->getType() << " is already equiped by another Character" RESET << std::endl;
		return;
	}
	int i = 0;
	while (this->_inventory[i] && this->_inventory[i] != m)
		i++;
	if (i >= 4){
		std::cout << RED "Inventory is full!! Unequip a materia to free space" RESET << std::endl;
		return;
	}
	if (this->_inventory[i] == m){
		std::cout << RED "The materia " << m->getType() << " is already on the inventory, no need to add" RESET << std::endl;
		return;
	}
	if (m->atFloor)
		Floor::getInstance()->removeMateria(m);//limpar a materia do chao
	this->_inventory[i] = m;
	std::cout << GREEN << m->getType() << " added to " << this->getName() << "'s inventory" << RESET << std::endl;
	m->isEquiped = true;
}

void Character::unequip(int idx){
	Floor *floor = Floor::getInstance();//singleton
	AMateria *toUnequip = this->_inventory[idx];
	if (idx < 0 || idx > 3)
		std::cout << RED "Please input an index between 0 and 3 for the inventory" RESET << std::endl;
	else if (!toUnequip)
		std::cout << RED << this->_name << " doesn't have any materia on the slot " << idx << RESET << std::endl;
	else {
		this->_inventory[idx] = NULL;
		std::cout << toUnequip->getType() << " left on the floor by " << this->getName() << std::endl;
		floor->leaveMateriaAtFloor(toUnequip);
	}
}

//*trigger*
void Character::use(int idx, ICharacter& target){
	if (idx < 0 || idx > 3)
		std::cout << RED "Please input an index between 0 and 3 for the inventory" RESET << std::endl;
	else if (!this->_inventory[idx])
		std::cout << RED << this->_name << " doesn't have any materia on the slot " << idx << RESET << std::endl;
	else
		this->_inventory[idx]->use(target);//calls function use of AMateria (Ice or Cure) for the target
}

void Character::copyInventory(const Character &src) {
	for (int i = 0; i < 4; i++){
/* 		if (this->_inventory[i])
			delete (this->_inventory[i]); */
		this->_inventory[i] = NULL;
		if (src._inventory[i])
			this->_inventory[i] = src._inventory[i]->clone();
	}
}