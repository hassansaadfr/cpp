#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int	main(void)
{
	Zombie	*horde;

	// Allocate Zero zombies
	std::cout << "Allocate 0 zombies" << std::endl;
	horde = zombieHorde(0, "Casper");
	if (!horde)
		return (1);
	delete [] horde;

	// Allocate 10 zombies
	std::cout << "Allocate 10 zombies" << std::endl;
	horde = zombieHorde(10, "FrankenHorde");
	if (!horde)
		return (1);
	delete [] horde;

	return (0);
}
