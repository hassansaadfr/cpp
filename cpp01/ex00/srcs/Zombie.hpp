#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class Zombie {
	public:
		Zombie(std::string name);
		~Zombie(void);

		void	set_name(std::string name);

	private:
		std::string _name;
		void		_announce(void) const;
};

#endif
