#ifndef HUMAN_B_CLASS_H
# define HUMAN_B_CLASS_H

#include <iostream>
#include "Weapon.hpp"

class HumanB {
	public:
		HumanB(void);
		HumanB(std::string name);
		~HumanB(void);

		void		attack(void) const;

		std::string	get_name(void) const;
		std::string	get_weapon(void) const;

		void		set_name(std::string name);
		void		setWeapon(Weapon &weapon);
	private:
		std::string	_name;
		Weapon		*_weapon;
};

#endif
