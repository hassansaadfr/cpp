#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat sarkozy("Sarkozy", 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat macron("Macron", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat melanchon("Melanchon", 150);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat marine("Marine", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}
