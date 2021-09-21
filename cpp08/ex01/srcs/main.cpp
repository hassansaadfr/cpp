#include "Span.hpp"
#include <stdlib.h>
#include <list>

int	main(void)
{
	srand(time(0));
	std::list<int> lst;

	for (size_t i = 0; i < 10000; i++)
		lst.push_back(rand() % 100000 + 1);

	Span big = Span(10001);

	try
	{
		std::cout << big.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	try
	{
		big.addNumber(1000);
		std::cout << big.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	try
	{
		big.addNumber(lst.begin(), lst.end());
		std::cout << big.shortestSpan() << std::endl;
		std::cout << big.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		big.addNumber(42);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

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
