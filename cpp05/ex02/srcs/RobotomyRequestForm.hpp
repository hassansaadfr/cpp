#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

# include <iostream>
# include "Form.hpp"

class RobotomyRequestForm : public Form
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm(void);
		RobotomyRequestForm(RobotomyRequestForm const &src);

		void		execute(Bureaucrat const &michel) const;
	private:
		std::string					_target;
		RobotomyRequestForm&		operator=(RobotomyRequestForm const &src);
};

std::ostream &		operator<<(std::ostream &o, RobotomyRequestForm const &src);

#endif
