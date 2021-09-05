#include "Fixed.hpp"
#include <iostream>
#include <tgmath.h>

Fixed::Fixed(void): _value(0)
{}

Fixed::Fixed(int const value) : _value(value << _bits)
{}

Fixed::Fixed(float const value) : _value(roundf(value * (1 << _bits)))
{}

Fixed::Fixed(Fixed const &src)
{
	*this = src;
}

Fixed::~Fixed(void)
{}

float	Fixed::toFloat(void) const
{
	return (float)this->_value / (float)(1 << this->_bits);
}

int		Fixed::toInt(void) const
{
	return (int)(this->_value >> this->_bits);
}

int		Fixed::getRawBits(void) const
{
	return this->_value;
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

std::ostream &operator<<(std::ostream &o, const Fixed &src)
{
	o << src.toFloat();
	return (o);
}

Fixed 	&Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

Fixed 	&Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed 	&Fixed::min(Fixed const &a, Fixed const &b)
{
	return (Fixed(a) < b ? a : b);
}

const Fixed 	&Fixed::max(Fixed const &a, Fixed const &b)
{
	return (Fixed(a) > b ? a : b);
}

Fixed&	Fixed::operator=(Fixed const &src)
{
	if (this != &src)
		this->_value = src.getRawBits();
	return *this;
}

Fixed&		Fixed::operator+(Fixed const &src)
{
	_value += src.getRawBits();
	return *this;
}

Fixed&		Fixed::operator-(Fixed const &src)
{
	_value -= src.getRawBits();
	return *this;
}

Fixed&		Fixed::operator*(Fixed const &src)
{
	_value = (getRawBits() * src.getRawBits()) >> _bits;
	return *this;
}

Fixed&		Fixed::operator/(Fixed const &src)
{
	_value = (getRawBits() << _bits) / src.getRawBits();
	return *this;
}

bool		Fixed::operator>(Fixed const &src) { return _value > src.getRawBits(); }
bool		Fixed::operator<(Fixed const &src) { return _value < src.getRawBits(); }
bool		Fixed::operator>=(Fixed const &src) { return _value >= src.getRawBits(); }
bool		Fixed::operator<=(Fixed const &src) { return _value <= src.getRawBits(); }
bool		Fixed::operator==(Fixed const &src) { return _value == src.getRawBits(); }
bool		Fixed::operator!=(Fixed const &src) { return _value != src.getRawBits(); }

Fixed&				Fixed::operator++(void)
{
	_value += 1 << _bits;
	return *this;
}

Fixed&				Fixed::operator--(void)
{
	_value -= 1 << _bits;
	return *this;
}

Fixed				Fixed::operator++(int)
{
	Fixed	old = *this;
	operator++();
	return old;
}

Fixed				Fixed::operator--(int)
{
	Fixed	old = *this;
	operator--();
	return old;
}
