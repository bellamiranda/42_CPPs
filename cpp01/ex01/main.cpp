#include "Zombie.hpp"

int	main(int argc, char **argv)
{
	if (argc % 2 != 1){
		std::cout << RED << "Please follow the rules 🚨" << std::endl;
		return (1);
	}
	for (int i = 1; argv[i]; i += 2){
		int N = std::atoi(argv[i]);
		if (!N){
			std::cout << RED << "FIRST INFORMATION HAS TO BE A NUMBER 💥" << RESET << std::endl;
			return (1);
		}
		Zombie *horde = zombieHorde(N, argv[i + 1]);
		if (horde)
		{
			for (int j = 0; j < N; j++)
				horde[j].announce();
			delete[] (horde);
		}
		std::cout << std::endl;
	}
	Zombie *horde = zombieHorde(0, "TEST");//test if no zombie is created
	if (horde)
	{
		for (int i = 0; i < 0; i++)
			horde[i].announce();
		delete[] (horde);
	}
	return (0);
}