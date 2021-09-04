#ifndef DOG_H
# define DOG_H

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>

class Dog : public Animal
{
	public:
		Dog(void);
		virtual ~Dog(void);
		Dog(Dog const &src);

		Dog&			operator=(Dog const &src);
		virtual void	makeSound(void) const;
	private:
		Brain	*brain;
};

std::ostream &		operator<<(std::ostream &o, Dog const &src);

#endif
