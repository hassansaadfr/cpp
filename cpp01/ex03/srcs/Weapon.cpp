#include "Weapon.hpp"

Weapon::Weapon(void)
{}

Weapon::Weapon(std::string type)
{
	this->setType(type);
}

Weapon::~Weapon(void){}

const std::string &Weapon::getType(void) const
{
	std::string	const &ref = this->_type;

	return ref;
}

void		Weapon::setType(std::string type)
{
	this->_type = type;
}
