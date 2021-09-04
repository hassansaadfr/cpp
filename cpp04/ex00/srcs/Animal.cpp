#include "Animal.hpp"
#include <iostream>

Animal::Animal(void)
{
	std::cout << "Animal Default constructor called" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal Destructor called" << std::endl;
}

Animal&	Animal::operator=(Animal const &src)
{
	std::cout << "Animal Copy constructor called" << std::endl;
	if (this != &src)
		_type = src.getType();
	return *this;
}

std::string		Animal::getType(void) const
{
	return _type;
}

void			Animal::setType(std::string type)
{
	_type = type;
}

void			Animal::makeSound(void) const
{
	std::cout << "Animal does not have a sound ..." << std::endl;
}

std::ostream	&operator<<(std::ostream &o, Animal const &src)
{
	o << src.getType();
	return o;
}
