#ifndef FORM_H
# define FORM_H

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form(std::string name, int grade, int gradeToExecute);
		~Form(void);

		Form(Form const &src);

		Form&				beSigned(Bureaucrat michel);

		std::string			getName(void) const;
		int					getGrade(void) const;
		bool				getIsSigned(void) const;
		int					getGradeToExecute(void) const;
		virtual void		execute(Bureaucrat const &michel) const = 0;
		bool				canExecute(Bureaucrat const &michel) const;
	private:
		std::string const	_name;
		int const			_gradeToSign;
		int const			_gradeToExecute;
		bool				_isSigned;
		Form&				operator=(Form const &src);

	public:
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char*	what(void) const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char*	what(void) const throw();
		};
		class FormNotSigned: public std::exception
		{
			public:
				virtual const char*	what(void) const throw();
		};
		class AlreadySigned: public std::exception
		{
			public:
				virtual const char*	what(void) const throw();
		};
};

std::ostream &		operator<<(std::ostream &o, Form const &src);

#endif
