#include "Cat.hpp"
#include <iostream>

Cat::Cat(void)
{
	setType("Cat");
	std::cout << "Cat Default constructor called" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat Destructor called" << std::endl;
}

Cat&	Cat::operator=(Cat const &src)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	if (this != &src)
		_type = src.getType();
	return *this;
}

void			Cat::makeSound(void) const
{
	std::cout << "Miaou Miaou" << std::endl;
}

std::ostream	&operator<<(std::ostream &o, Cat const &src)
{
	o << src.getType();
	return o;
}
