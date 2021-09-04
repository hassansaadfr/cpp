#include "Fixed.hpp"
#include <iostream>
#include <tgmath.h>

Fixed::Fixed(void): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const value) : _value(value << _bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const value) : _value(roundf(value * (1 << _bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

float	Fixed::toFloat(void) const
{
	return (float)this->_value / (float)(1 << this->_bits);
}

int		Fixed::toInt(void) const
{
	return (int)(this->_value >> this->_bits);
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

std::ostream &operator<<(std::ostream &o, const Fixed &src)
{
	o << src.toFloat();
	return (o);
}
