#include "Cat.hpp"
#include <iostream>

Cat::Cat(void)
{
	brain = new Brain();
	setType("Cat");
	std::cout << "Cat Default constructor called" << std::endl;
}

Cat::~Cat(void)
{
	delete brain;
	std::cout << "Cat Destructor called" << std::endl;
}

Cat::Cat(Cat const &src)
{
	*this = src;
}

Cat&	Cat::operator=(Cat const &src)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	if (this != &src)
	{
		_type = src.getType();
		brain = src.brain;
	}
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
