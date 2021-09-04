#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"
# include <iostream>

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		~ScavTrap(void);
		ScavTrap(ScavTrap const &src);

		ScavTrap&		operator=(ScavTrap const &src);

		virtual void	attack(std::string const & target);
		void			guardGate(void);
};

std::ostream &		operator<<(std::ostream &o, ScavTrap const &src);

#endif
