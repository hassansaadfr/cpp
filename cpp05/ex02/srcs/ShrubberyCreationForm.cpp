#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("ShrubberyCreationForm", 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("ShrubberyCreationForm", 145, 137), _target(target)
{}


ShrubberyCreationForm::~ShrubberyCreationForm(void)
{}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
	return *this;
}

void	ShrubberyCreationForm::_print_three(std::ofstream &o) const
{
	o << "+-----------------+" << std::endl;
	o << "|                 |" << std::endl;
	o << "|                 |" << std::endl;
	o << "|                 |" << std::endl;
	o << "|                 |" << std::endl;
	o << "|                 |" << std::endl;
	o << "|                 |" << std::endl;
	o << "+------+---+------+" << std::endl;
	o << "       |   |" << std::endl;
	o << "       |   |" << std::endl;
	o << "       |   |" << std::endl;
	o << "       |   |" << std::endl;
	o << "       |   |" << std::endl;
	o << "       |   |" << std::endl;
	o << "       |   |" << std::endl;
	o << "       |   |" << std::endl;
	o << "       |   |" << std::endl;
	o << "       |   |" << std::endl;
	o << "       |   |" << std::endl;
	o << "       |   |" << std::endl;
	o << "       |   |" << std::endl;
	o << "       |   |" << std::endl;
	o << "       |   |" << std::endl;
	o << "       +---+" << std::endl;

}

void		ShrubberyCreationForm::execute(Bureaucrat const &michel) const
{
	if (this->canExecute(michel))
	{
		std::ofstream ofs(_target + "_shruberry");
		if (ofs.fail())
			throw std::ios::failure("Cant write in new file");
		_print_three(ofs);
		ofs.close();
	}
	else
		throw Form::GradeTooHighException("Grade too low");
}

std::ostream &		operator<<(std::ostream &o, ShrubberyCreationForm const &src)
{
	o << "ShrubberyCreationForm : " << src.getName() << ", grade to sign : " << src.getGrade() << ", grade to execute : " << src.getGradeToExecute() << ", is signed : " << src.getIsSigned();
}
