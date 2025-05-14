#pragma once
#ifndef FLOOR_HPP
#define FLOOR_HPP

#include "AMateria.hpp"

typedef struct s_listOfMaterias {
	AMateria	*content;
	s_listOfMaterias *next;
}	listOfMaterias;


class Floor {
private:
	static Floor	*_instance;
	listOfMaterias	*_matAtFloor;
	//prevents the creation of multiple instances
	Floor();
	Floor(const Floor&);
	Floor& operator=(const Floor&);
	~Floor();
public:
	static Floor* getInstance();
	listOfMaterias *getMateriasAtFloor() const;
	void leaveMateriaAtFloor(AMateria* m);
	void removeMateria(AMateria *m);
	void cleanFloor();
	void displayFloor();
};

#endif