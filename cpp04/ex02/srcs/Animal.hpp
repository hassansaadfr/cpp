#ifndef ANIMAL_H
# define ANIMAL_H

# include <iostream>

class Animal
{
	public:
		Animal(void);
		virtual ~Animal(void);
		Animal(Animal const &src);

		Animal&			operator=(Animal const &src);

		virtual void	makeSound(void) const = 0;
		std::string		getType(void) const;
		void			setType(std::string type);
	protected:
		std::string		_type;
};

std::ostream 			&operator<<(std::ostream &o, Animal const &src);

#endif
