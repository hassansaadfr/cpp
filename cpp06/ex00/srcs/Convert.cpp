#include "Convert.hpp"
#include <limits>
#include <math.h>
Convert::Convert(void)
{}

Convert::Convert(char *value) :_value(std::stod(value))
{}

Convert::Convert(Convert const &src): _value(src.get_value())
{}

Convert::~Convert(void)
{}

Convert&	Convert::operator=(Convert const &src)
{
	if (this != &src)
		this->_value = src.get_value();
	return *this;
}

double		Convert::get_value(void) const
{
	return _value;
}

std::ostream &		operator<<(std::ostream &o, Convert const &src)
{
	return o << src.get_value();
}

const char*	Convert::impossibleCast::what() const throw()
{
	return "impossible";
}

char			Convert::to_char(void) const
{
	if (_value == std::numeric_limits<float>::infinity() || isnan(_value) || _value > std::numeric_limits<int>::max() || _value < 0)
		throw Convert::impossibleCast();
	return static_cast<char>(_value);
}

int				Convert::to_int(void) const
{
	if (_value == std::numeric_limits<float>::infinity() || isnan(_value) || _value > std::numeric_limits<int>::max() || _value < std::numeric_limits<int>::min())
	{
		throw Convert::impossibleCast();
	}
	return static_cast<int>(_value);
}

float			Convert::to_float(void) const
{
	if (_value < std::numeric_limits<float>::min() || _value > std::numeric_limits<float>::max())
		throw Convert::impossibleCast();
	return static_cast<float>(_value);
}

double			Convert::to_double(void) const
{
	return _value;
}
