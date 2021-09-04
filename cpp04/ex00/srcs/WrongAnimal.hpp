#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

# include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal(void);
		virtual ~WrongAnimal(void);
		WrongAnimal(WrongAnimal const &src);

		WrongAnimal&		operator=(WrongAnimal const &src);
		void				makeSound(void) const;
};

std::ostream &				operator<<(std::ostream &o, WrongAnimal const &src);

#endif
