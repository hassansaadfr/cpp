#include "Whatever.hpp"
#include <iostream>

void	mandatory(void)
{
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}

int	main(void)
{
	int		a = 10;
	int		b = 42;

	float	c = 42.42;
	float	d = 88.9;

	std::string e = "lol";
	std::string f = "yay";

	std::cout << "explicit int Min\t:\t\t" << ::min<int>(a, b) << std::endl;
	std::cout << "explicit int Max\t:\t\t" << max<int>(a, b) << std::endl;
	std::cout << "implicit int Min\t:\t\t" << min(a, b) << std::endl;
	std::cout << "implicit int Max\t:\t\t" << max(a, b) << std::endl;
	std::cout << "explicit float Min\t:\t\t" << min<float>(c, d) << std::endl;
	std::cout << "explicit float Max\t:\t\t" << max<float>(c, d) << std::endl;
	std::cout << "implicit float Min\t:\t\t" << min(c, d) << std::endl;
	std::cout << "implicit float Max\t:\t\t" << max(c, d) << std::endl;

	std::cout << "-------------------" << std::endl;
	std::cout << "explicit Swap a 10 and b 42" << std::endl;
	swap<int>(a, b);
	std::cout << "a : " << a << std::endl;
	std::cout << "b : " << b << std::endl;
	std::cout << "implicit Swap a 42 and b 10" << std::endl;
	swap<int>(a, b);
	std::cout << "a : " << a << std::endl;
	std::cout << "b : " << b << std::endl;

	std::cout << "------------------" << std::endl;
	std::cout << "mandatory test part" << std::endl;

	mandatory();
}
