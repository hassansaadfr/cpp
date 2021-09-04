#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _weapon(NULL), _name(name) {}

HumanB::~HumanB(void)
{
	std::cout << this->get_name() << " was destroyed" << std::endl;
}

void	HumanB::attack(void) const
{
	std::cout << this->get_name() <<  " attacks with his " << this->get_weapon() << std::endl;
}

std::string	HumanB::get_name(void) const
{
	return this->_name;
}
std::string	HumanB::get_weapon(void) const
{
	return this->_weapon->getType();
}

void	HumanB::set_name(std::string name)
{
	this->_name = name;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
