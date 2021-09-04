#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

# include <iostream>
# include "Form.hpp"

class ShrubberyCreationForm: public Form
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);

		void		execute(Bureaucrat const &michel) const;
	private:
		void						_print_three(std::ofstream &o) const;
		std::string					_target;
		ShrubberyCreationForm&		operator=(ShrubberyCreationForm const &src);
};

std::ostream &		operator<<(std::ostream &o, ShrubberyCreationForm const &src);

#endif
