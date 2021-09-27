#include "Convert.hpp"
#include <limits>
#include <math.h>
#include <string.h>

int		get_nb_char(std::string s, char to_find)
{
	size_t	len = s.length();
	int		num = 0;

	for (size_t i = 0; i < len; i++)
	{
		if (s[i] == to_find)
			num++;
	}
	return num;
}

double parse_string(char* s)
{
	size_t	len = strlen(s);

	if (len == 1)
	{
		if (isdigit(s[0]))
			return atof(s);
		return s[0];
	}
	else if (len > 1)
	{
		std::string	str(s);
		int			dot = get_nb_char(str, '.');
		int			sign = get_nb_char(str, '-') + get_nb_char(str, '+');
		int			f = get_nb_char(str, 'f');

		if (dot > 1 || sign > 1 || f > 1)
			throw std::exception();
		dot = 0;
		size_t len = str.length();

		for (size_t i = 0; i < len; i++)
		{
			if (strchr("+-.f0123456789", s[i]) == NULL)
				throw std::exception();
			else if ((s[i] == '+' || s[i] == '-') && i != 0)
				throw std::exception();
			else if (s[i] == '.')
			{
				if (i == 0 || i == len - 1 || dot != 0)
					throw std::exception();
				if (!isdigit(s[i - 1]) || !isdigit(s[i + 1]))
					throw std::exception();
				dot++;
			}
			else if (s[i] == 'f')
			{
				if (i != len - 1)
					throw std::exception();
			}
		}
		return atof(s);
	}
	else
		throw std::exception();
}

Convert::Convert(void)
{}

Convert::Convert(char *value)
{
	std::string tmp = value;
	if (tmp == "nan" || tmp == "inf" || tmp == "+inf" || tmp == "-inf"
		|| tmp == "nanf" || tmp == "inff" || tmp == "+inff" || tmp == "-inff"
	)
	{
		_value = atof(value);
	}
	else
		_value = parse_string(value);
}

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
	if (_value < -std::numeric_limits<float>::max() - 1 || _value > std::numeric_limits<float>::max())
	{
		if (_value != std::numeric_limits<float>::infinity() && _value != -std::numeric_limits<float>::infinity())
			throw Convert::impossibleCast();
	}
	return static_cast<float>(_value);
}

double			Convert::to_double(void) const
{
	return _value;
}
