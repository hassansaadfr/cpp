#include "Span.hpp"
#include <stdlib.h>
#include <list>

int	main(void)
{
	srand(time(0));
	std::list<int> lst;

	for (size_t i = 0; i < 10; i++)
		lst.push_back(rand() % 100000 + 1);

	Span big = Span(10);
	big.addNumber(lst.begin(), lst.end());
	std::cout << big.shortestSpan() << std::endl;
	std::cout << big.longestSpan() << std::endl;

	try
	{
		Span sp = Span(5);
		sp.addNumber(-10);
		sp.addNumber(30);
		sp.addNumber(-1);
		sp.addNumber(5);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
