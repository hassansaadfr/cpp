#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int	main(void)
{
	Zombie	*frankenheap = newZombie("frankenheap");
	randomChump("Frankenstack");
	delete(frankenheap);
	return (0);
}
