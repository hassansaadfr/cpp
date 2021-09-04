#ifndef WRONGCAT_H
# define WRONGCAT_H

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		virtual ~WrongCat(void);
		WrongCat(WrongCat const &src);

		WrongCat&		operator=(WrongCat const &src);
		void			makeSound(void) const;
};

std::ostream &		operator<<(std::ostream &o, WrongCat const &src);

#endif
