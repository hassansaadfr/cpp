#include "RobotomyRequestForm.hpp"
#include <fstream>

RobotomyRequestForm::RobotomyRequestForm(void) : Form("RobotomyRequestForm", 72, 45)
{}

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("RobotomyRequestForm", 145, 137), _target(target)
{}

RobotomyRequestForm::~RobotomyRequestForm(void)
{}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
	_target = src._target;
	return *this;
}
void		RobotomyRequestForm::execute(Bureaucrat const &michel) const
{
	if (this->canExecute(michel))
		std::cout << "Brrrrrrrrt Brrrrrrrrt " << _target << " was robotized" << std::endl;
	else
		std::cout << "form is not signed" << std::endl;
}

std::ostream &		operator<<(std::ostream &o, RobotomyRequestForm const &src)
{
	o << "RobotomyRequestForm : " << src.getName() << ", grade to sign : " << src.getGrade() << ", grade to execute : " << src.getGradeToExecute() << ", is signed : " << src.getIsSigned();
	return o;
}
