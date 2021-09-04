#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void)
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitpoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap Assignation constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << _name << " has entered in gatekeeper mode" << std::endl;
}

void	ScavTrap::attack(std::string const & target)
{
	if (this->_energyPoints <= 0)
		std::cout << "ScavTrap " << this->_name << " cant attack " << target <<
			" because he is dead" << std::endl;
	else
		std::cout << "ScavTrap " << this->_name << " attack " << target <<
			", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

std::ostream	&operator<<(std::ostream &o, ScavTrap const &src)
{
	o << src.get_name();
}
