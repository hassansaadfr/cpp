#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon)
{
	this->set_name(name);
}

HumanA::~HumanA(void)
{
	std::cout << this->get_name() << " was destroyed" << std::endl;
}

void	HumanA::attack(void) const
{
	std::cout << this->get_name() <<  " attacks with his " << this->get_weapon() << std::endl;
}

std::string	HumanA::get_name(void) const
{
	return this->_name;
}
std::string	HumanA::get_weapon(void) const
{
	return this->_weapon.getType();
}

void	HumanA::set_name(std::string name)
{
	this->_name = name;
}
