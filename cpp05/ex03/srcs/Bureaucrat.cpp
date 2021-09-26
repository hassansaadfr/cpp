/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 13:39:35 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/09/26 13:06:43 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void)
{}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	setGrade(grade);
}

Bureaucrat::~Bureaucrat(void)
{}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const &src)
{
	if (this != &src)
		this->_grade = src.getGrade();
	return *this;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src.getName()), _grade(src.getGrade())
{}

void			Bureaucrat::setGrade(int grade)
{
	if (grade > 150 || grade < 1)
	{
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
	}
	else
		_grade = grade;
}

int				Bureaucrat::getGrade(void) const
{
	return _grade;
}

std::string		Bureaucrat::getName(void) const
{
	return _name;
}

void			Bureaucrat::incrementGrade(void)
{
	setGrade(_grade - 1);
}

void			Bureaucrat::decrementGrade(void)
{
	setGrade(_grade + 1);
}

void			Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " sign form" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << _name << " cannot sign because: " << e.what() << std::endl;
	}
}

void			Bureaucrat::executeForm(Form const & form)
{
	try
	{
		form.execute(*this);
		std::cout << getName() << " successfully executed form " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << getName() << " cant execute form " << form.getName() << std::endl;
		std::cerr << e.what() << '\n';
	}
}

std::ostream &		operator<<(std::ostream &o, Bureaucrat const &src)
{
	o << src.getName() << ", bureaucrat grade" << src.getGrade();
	return o;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}
