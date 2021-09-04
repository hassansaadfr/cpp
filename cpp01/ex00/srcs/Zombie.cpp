#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->set_name(name);
	this->_announce();
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " got shot in the head" << std::endl;
}

void	Zombie::_announce(void) const
{
	std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name(std::string name) { this->_name = name; }
