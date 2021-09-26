#ifndef INTERN_H
# define INTERN_H

# include <iostream>
# include "Form.hpp"

class Intern
{
	public:
		Intern(void);
		~Intern(void);
		Intern(Intern const &src);

		Intern&		operator=(Intern const &src);
		Form*		makeForm(std::string, std::string) const;
};

std::ostream &		operator<<(std::ostream &o, Intern const &src);

#endif
