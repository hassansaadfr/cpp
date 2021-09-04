#include "Form.hpp"

Form::Form(std::string name, int grade, int gradeToExecute) : _name(name), _gradeToSign(grade), _gradeToExecute(gradeToExecute), _isSigned(false)
{}

Form::~Form(void)
{}

Form&		Form::operator=(Form const &src)
{
	return *this;
}

std::string	Form::getName(void) const
{
	return _name;
}

int			Form::getGrade(void) const
{
	return _gradeToSign;
}

bool		Form::getIsSigned(void) const
{
	return _isSigned;
}

int			Form::getGradeToExecute(void) const
{
	return _gradeToExecute;
}


Form&		Form::beSigned(Bureaucrat michel)
{
	if (michel.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException("Grade too low buddy you need promotion");
	_isSigned = true;
	std::cout << "Form is successfully signed" << std::endl;
	return *this;
}

bool		Form::canExecute(Bureaucrat const &michel) const
{
	if (_isSigned == false)
		return false;
	if (getGradeToExecute() > michel.getGrade())
		throw Form::GradeTooHighException("The form level is too high for you asshole");
	return true;
}

Form::GradeTooLowException::GradeTooLowException(std::string reason) : _reason(reason) {}
Form::GradeTooHighException::GradeTooHighException(std::string reason) : _reason(reason) {}

const char*	Form::GradeTooHighException::what(void) const throw()
{
	return _reason.data();
}

const char*	Form::GradeTooLowException::what(void) const throw()
{
	return _reason.data();
}

std::ostream &		operator<<(std::ostream &o, Form const &src)
{
	o << "Form : " << src.getName() << ", grade to sign : " << src.getGrade() << ", grade to execute : " << src.getGradeToExecute() << ", is signed : " << src.getIsSigned();
}
