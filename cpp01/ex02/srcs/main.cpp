#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string	*ptr = &str;
	std::string	&ref = str;

	std::cout << "Address of string using ptr: " << std::endl << ptr << std::endl;
	std::cout << "Address of string using ref: " << std::endl << &ref << std::endl;
	std::cout << "Value of string using ptr: " << std::endl << *ptr << std::endl;
	std::cout << "Value of string using ref: " << std::endl << ref << std::endl;
	return 0;
}
