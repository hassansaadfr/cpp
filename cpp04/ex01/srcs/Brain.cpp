#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain Default constructor called" << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Brain Destructor called" << std::endl;
}

Brain::Brain(Brain const &src)
{
	*this = src;
}

Brain&			Brain::operator=(Brain const &src)
{
	if (this != &src)
	{
		for (unsigned int i = 0; i < 100; i++)
			_ideas[i] = src._ideas[i];
	}
	return *this;
}

std::string		Brain::operator[](unsigned int i)
{
	return _ideas[i];
}

std::ostream	&operator<<(std::ostream &o, Brain const &src)
{
	o << &src;
	return o;
}
