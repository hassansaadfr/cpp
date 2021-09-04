#include "Karen.hpp"
#include <iostream>

int	main(int ac, char **av)
{
	if (ac == 2)
		Karen karen(av[1]);
	else
	{
		std::cout << "-----------" << std::endl;
		Karen one("DEBUG");
		std::cout << "-----------" << std::endl;
		Karen two("INFO");
		std::cout << "-----------" << std::endl;
		Karen three("WARNING");
		std::cout << "-----------" << std::endl;
		Karen four("ERROR");
		std::cout << "-----------" << std::endl;
		Karen five("foo");
		std::cout << "-----------" << std::endl;
	}
	return (0);
}
