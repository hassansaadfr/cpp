#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _hitpoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitpoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Assignation constructor called" << std::endl;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const &src)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	if (this != &src)
	{
		this->_attackDamage = src.get_attackDamage();
		this->_energyPoints = src.get_energyPoints();
		this->_hitpoints = src.get_hitPoints();
	}
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->_name << " was destroyed" << std::endl;
}

void			ClapTrap::attack(std::string const & target)
{
	if (this->_energyPoints <= 0)
		std::cout << "ClapTrap " << this->_name << " cant attack " << target <<
			" because he is dead" << std::endl;
	else
		std::cout << "ClapTrap " << this->_name << " attack " << target <<
			", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void 			ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead ... he cant take more damages" << std::endl;
		return ;
	}
	this->_energyPoints -= (int)amount;
	if (this->_energyPoints <= 0)
		std::cout << "ClapTrap " << this->_name << " was killed, he need to be repaired" << std::endl;
	else
		std::cout << "ClapTrap " << this->_name << " loose " << amount << " energy points. OUCHH he actually have "
			<< this->_energyPoints << std::endl;
}

void 			ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " will regain " << amount << " energy points" << std::endl;
	if (this->_energyPoints < 0)
		this->_energyPoints = 0;
	this->_energyPoints += (int)amount;
}

int				ClapTrap::get_hitPoints(void) const
{
	return this->_hitpoints;
}

int				ClapTrap::get_energyPoints(void) const
{
	return this->_energyPoints;
}

int				ClapTrap::get_attackDamage(void) const
{
	return this->_attackDamage;
}

void			ClapTrap::set_hitPoints(int hitpoints)
{
	this->_hitpoints = hitpoints;
}

void			ClapTrap::set_energyPoints(int energyPoints)
{
	this->_energyPoints = energyPoints;
}

void			ClapTrap::set_attackDamage(int attackDamage)
{
	this->_attackDamage = attackDamage;
}

std::string		ClapTrap::get_name(void) const
{
	return _name;
}

std::ostream	&operator<<(std::ostream &o, ClapTrap const &src)
{
	o << src.get_name();
	return o;
}
