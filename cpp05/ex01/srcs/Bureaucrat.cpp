/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 13:39:35 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/09/25 17:43:25 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void)
{
	std::cout << "Bureaucrat Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << "Bureaucrat Assignation constructor called" << std::endl;
	setGrade(grade);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat Destructor called" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const &src)
{
	std::cout << "Operator overload called" << std::endl;
	if (this != &src)
		this->_grade = src.getGrade();
	return *this;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src.getName()), _grade(src.getGrade())
{
	std::cout << "Copy constructor called" << std::endl;
}

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

void			Bureaucrat::signForm(Form form)
{
	form.beSigned(*this);
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
