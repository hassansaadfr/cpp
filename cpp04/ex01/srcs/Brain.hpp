#ifndef BRAIN_H
# define BRAIN_H

# include <iostream>

class Brain
{
	public:
		Brain(void);
		~Brain(void);
		Brain(Brain const &src);

		Brain&		operator=(Brain const &src);
		std::string	operator[](unsigned int i);
	private:
		std::string	_ideas[100];
};

std::ostream &		operator<<(std::ostream &o, Brain const &src);

#endif
