#ifndef CAT_H
# define CAT_H

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat(void);
		virtual ~Cat(void);
		Cat(Cat const &src);

		Cat&			operator=(Cat const &src);
		virtual void	makeSound(void) const;
	private:
		Brain	*brain;
};

std::ostream &		operator<<(std::ostream &o, Cat const &src);

#endif
