#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>

class ClapTrap
{
	public:
		// Constructors
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &src);

		// Destructor
		~ClapTrap(void);

		// Overloading equal
		ClapTrap&		operator=(ClapTrap const &src);

		// Utils
		void			attack(std::string const & target);
		void 			takeDamage(unsigned int amount);
		void 			beRepaired(unsigned int amount);

		// Getters
		std::string		get_name(void) const;
		int				get_hitPoints(void) const;
		int				get_energyPoints(void) const;
		int				get_attackDamage(void) const;

		// Setters
		void			set_hitPoints(int hitpoints);
		void			set_energyPoints(int energyPoints);
		void			set_attackDamage(int attackDamage);

	private:
		std::string		_name;
		int				_hitpoints;
		int				_energyPoints;
		int				_attackDamage;

};

std::ostream &		operator<<(std::ostream &o, ClapTrap const &src);

#endif
