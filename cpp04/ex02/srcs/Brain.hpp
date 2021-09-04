#ifndef BRAIN_H
# define BRAIN_H

# include <iostream>

class Brain
{
	public:
		Brain(void);
		~Brain(void);
	private:
		std::string	_ideas[100];
};

#endif
