#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string name);
		~FragTrap(void);
		FragTrap(FragTrap const &src);

		FragTrap&		operator=(FragTrap const &src);

		void			highFivesGuys(void);
};

std::ostream &		operator<<(std::ostream &o, FragTrap const &src);

#endif
