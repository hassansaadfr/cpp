#ifndef HUMAN_A_CLASS_H
# define HUMAN_A_CLASS_H

#include <iostream>
#include "Weapon.hpp"

class HumanA {
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);

		void		attack(void) const;

		std::string	get_name(void) const;
		std::string	get_weapon(void) const;

		void		set_name(std::string name);
	private:
		std::string _name;
		Weapon		&_weapon;
};

#endif
