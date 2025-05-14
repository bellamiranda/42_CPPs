#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main()
{
	std::cout << ORANGE " ----- SUBJECT TESTS ----- " RESET << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");//creates a clone, has to be deleted
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;


	std::cout << ORANGE "\n ----- DEEP COPY TEST ----- " RESET << std::endl;
	Character* john = new Character("john");
	john->equip(new Ice());
	john->equip(new Ice());
	john->equip(new Ice());
	john->equip(new Ice());
	Character* copy = new Character(*john);
	john->unequip(0);
	john->unequip(0);
	john->equip(new Ice());
	john->use(0, *copy);
	copy->use(1, *john);
	copy->unequip(1);
	copy->use(1, *john);
	copy->equip(new Cure());
	copy->use(1, *john);
	delete john;
	delete copy;
	Floor::getInstance()->displayFloor();
	Floor::getInstance()->cleanFloor();

	std::cout << ORANGE "\n ----- SINGLETON INSTANCE TEST ----- " RESET << std::endl;
	Floor* a = Floor::getInstance();
	Floor* b = Floor::getInstance();
	std::cout << "Singleton a == b? " << (a == b ? "✅ Yes" : "❌ No") << std::endl;

	std::cout << ORANGE "\n ----- FLOOR TEST ----- " RESET << std::endl;
	ICharacter* joao = new Character("Joao");
	ICharacter* maria = new Character("Maria");
	AMateria *ice = new Ice;
	AMateria *cure = new Cure;
	Floor *floor = Floor::getInstance();//always get the same floor
	joao->equip(ice);
	joao->equip(cure);
	joao->use(0, *maria);
	joao->use(1, *joao);
	joao->unequip(0);
	joao->unequip(1);
	floor->displayFloor();

	maria->equip(cure);
	maria->use(0, *maria);

	floor->displayFloor();
	floor->cleanFloor();
	delete joao;
	delete maria;

	return 0;
}

/* 
INTERFACES -> pure abstract classes, without any methods, attributes or constructors,
	with only pure virtual functions and can have virtual destructor
Floor *floor = Floor::getInstance(); -> SINGLETON
	guarantee that there is only ONE instance of floor in the program 
	that all the characters are sharing
*/