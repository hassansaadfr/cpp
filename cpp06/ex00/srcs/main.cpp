#include <iostream>
#include "Convert.hpp"
#include <iomanip>

int main(int ac, char **av)
{
	Convert to_convert;

	if (ac != 2)
	{
		std::cout << "usage:" << std::endl << "./a.out 42" << std::endl;;
		return 1;
	}
	try
	{
		to_convert = Convert(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return 1;
	}
	std::cout << "to char: ";
	try
	{
		char c = to_convert.to_char();
		if (c <= 32)
			std::cout << "not displayable" << std::endl;
		else
			std::cout << c << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "impossible" << std::endl;
	}
	std::cout << "to int: ";
	try
	{
		std::cout  << to_convert.to_int() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout  << e.what() << std::endl;
	}
	std::cout << "to float: ";
	try
	{
		std::cout << std::fixed << std::setprecision(1) << to_convert.to_float() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout  << e.what() << std::endl;
	}
	std::cout << "to double: " << to_convert.to_double() << std::endl;
	return 0;
}
