#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}

/* VERIFICAR:
USE NA CURE
COPYINVENTORY i=0 NA CHARACTER
FLOOR NA EQUIP
*/


/* 🧪 O que testar no main.cpp:
Criar um MateriaSource, aprender Ice e Cure
Criar magias e equipar em um Character
Usar magias em outro personagem
Testar cópia profunda de Character
Testar unequip() (não deve deletar a magia) */

/* 
Pure abstract classes are commonly called INTERFACES
Floor *floor = Floor::getInstance(); -> SINGLETON
	guarantee that there is only ONE floor in the program 
	that all the characters are sharing
*/