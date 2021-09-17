#include "Data.hpp"

Data::Data(void)
{}

Data::Data(int nb): _nb(nb)
{}

Data::~Data(void)
{}

Data::Data(Data const &src) : _nb(src.get_value())
{}

Data&	Data::operator=(Data const &src)
{
	if (this != &src)
		this->_nb = src.get_value();
	return *this;
}

bool	Data::operator==(Data const &src)
{
	return _nb == src.get_value();
}


int		Data::get_value(void) const
{
	return _nb;
}

std::ostream &	operator<<(std::ostream &o, Data const &src)
{
	o << src.get_value();
	return o;
}
