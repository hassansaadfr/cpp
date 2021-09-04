#include "Dog.hpp"
#include <iostream>

Dog::Dog(void)
{
	setType("Dog");
	std::cout << "Dog Default constructor called" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog Destructor called" << std::endl;
}

Dog&	Dog::operator=(Dog const &src)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	if (this != &src)
		_type = src.getType();
	return *this;
}

void			Dog::makeSound(void) const
{
	std::cout << "Waf waf" << std::endl;
}

std::ostream	&operator<<(std::ostream &o, Dog const &src)
{
	o << src.getType();
	return o;
}
