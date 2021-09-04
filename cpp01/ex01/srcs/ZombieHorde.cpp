#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *horde;

	try
	{
		horde = new Zombie[N];
		for (size_t i = 0; i < N; i++)
		{
			horde[i].set_name(name);
			horde[i].announce();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return horde;
}
