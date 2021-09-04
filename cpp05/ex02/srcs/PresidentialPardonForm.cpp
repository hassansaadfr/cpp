#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form("PresidentialPardonForm", 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("PresidentialPardonForm", 25, 5), _target(target)
{}

PresidentialPardonForm::~PresidentialPardonForm(void)
{}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
	return *this;
}

void		PresidentialPardonForm::execute(Bureaucrat const &michel) const
{
	if (this->canExecute(michel))
		std::cout << _target << _target << " has been forgiven by Zafod Beeblebrox." << std::endl;
	else
		std::cout << "form is not signed" << std::endl;
}

std::ostream &		operator<<(std::ostream &o, PresidentialPardonForm const &src)
{
	o << "PresidentialPardonForm : " << src.getName() << ", grade to sign : " << src.getGrade() << ", grade to execute : " << src.getGradeToExecute() << ", is signed : " << src.getIsSigned();
}
