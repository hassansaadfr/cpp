#include <iostream>
#include "Convert.hpp"
#include <iomanip>
#include <limits>
#include <math.h>

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
		float f = to_convert.to_float();

		if ((f > std::numeric_limits<float>::max() || f > -std::numeric_limits<float>::max() - 1) && std::string(av[1]).length() > 5)
			std::cout << "impossible" << std::endl;
		else
		{
			if (f == std::numeric_limits<float>::infinity())
				std::cout << "+";
			std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cout  << e.what() << std::endl;
	}
	std::cout << "to double: ";
	double d = to_convert.to_double();
	if ((d > std::numeric_limits<double>::max() || d < -std::numeric_limits<double>::max() - 1) && std::string(av[1]).length() > 5)
		std::cout << "impossible" << std::endl;
	else
	{
		if (d == std::numeric_limits<double>::infinity())
			std::cout << "+";
		std::cout << d << std::endl;
	}
	return 0;
}
