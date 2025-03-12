#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return (NULL);
	Zombie *horde = new Zombie[N];
	for (int i = 0; i < N; i++){
		std::ostringstream position;//creates an obj that works as a buffer to convert int to string
		position << name << " " << i + 1;//insert values to the object
		horde[i].setName(position.str());//extracts the string from the stream
	}
	return (horde);
}