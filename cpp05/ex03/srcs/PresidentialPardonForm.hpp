#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

# include <iostream>
# include "Form.hpp"

class PresidentialPardonForm: public Form
{
	public:
		PresidentialPardonForm(void);
		~PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &src);

		void		execute(Bureaucrat const &michel) const;
	private:
		std::string					_target;
		PresidentialPardonForm&		operator=(PresidentialPardonForm const &src);
};

std::ostream &		operator<<(std::ostream &o, PresidentialPardonForm const &src);

#endif
