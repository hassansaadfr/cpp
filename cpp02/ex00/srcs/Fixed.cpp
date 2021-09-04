#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;

}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed&	Fixed::operator=(Fixed const &src)
{
	std::cout << "Assignation constructor called" << std::endl;
	if (this != &src)
		this->_value = src.getRawBits();
	return *this;
}

int			Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void		Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

std::ostream	&operator<<(std::ostream &o, Fixed const &src)
{
	o << src.getRawBits();
}
