#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ScavTrap(name)
{
	_hitpoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap give me high five buddy" << std::endl;
}

std::ostream	&operator<<(std::ostream &o, FragTrap const &src)
{
	o << src.get_name();
	return o;
}
