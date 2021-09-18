#include "Iter.hpp"
#include <iostream>

template <typename T>
void	print_iter(T val)
{
	std::cout << val << std::endl;
}

int	main(void)
{
	std::string	words[4] = {"Bonjour", "Hello", "Hola", "Hi"};
	int			nb[4] = {8, 0, 42, -8};
	float		fl[4] = {42.0f, 21.42f, 10.12f, -42.42f};

	iter(words, 4, print_iter);
	iter(nb, 4, print_iter);
	iter(fl, 4, print_iter);
	return (0);
}
