#include "EasyFind.hpp"
#include <vector>
#include <iostream>

void	find(std::vector<int> &numbers, int n)
{
	try
	{
		int found = easyfind(numbers, n);
		std::cout << "Found: " << found << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << ": " << n << '\n';
	}
}

int	main(void)
{
	std::vector<int> numbers;

	numbers.push_back(42);
	numbers.push_back(43);
	numbers.push_back(48);

	find(numbers, 48);
	find(numbers, 10);
	find(numbers, 42);
	find(numbers, 422);

	return 0;
}
