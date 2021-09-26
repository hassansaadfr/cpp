#include "Form.hpp"

Form::Form(std::string name, int grade, int gradeToExecute) : _name(name), _gradeToSign(grade), _gradeToExecute(gradeToExecute), _isSigned(false)
{}

Form::~Form(void)
{}

Form::Form(Form const &src): _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute), _isSigned(src._isSigned)
{}

Form&		Form::operator=(Form const &src)
{
	this->_isSigned = src._isSigned;
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
		throw Form::GradeTooLowException();
	if (_isSigned == true)
		throw Form::AlreadySigned();
	_isSigned = true;
	std::cout << "Form is successfully signed" << std::endl;
	return *this;
}

bool		Form::canExecute(Bureaucrat const &michel) const
{
	if (_isSigned == false)
		throw Form::FormNotSigned();
	if (getGradeToExecute() > michel.getGrade())
		throw Form::GradeTooHighException();
	return true;
}

const char*	Form::FormNotSigned::what(void) const throw()
{
	return "The form is not signed";
}

const char*	Form::GradeTooHighException::what(void) const throw()
{
	return "grade too high";
}

const char*	Form::GradeTooLowException::what(void) const throw()
{
	return "grade too low";
}

const char*	Form::AlreadySigned::what(void) const throw()
{
	return "The form is already signed";
}

std::ostream &		operator<<(std::ostream &o, Form const &src)
{
	o << "Form : " << src.getName() << ", grade to sign : " << src.getGrade() << ", grade to execute : " << src.getGradeToExecute() << ", is signed : " << src.getIsSigned();
	return o;
}
