/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 13:39:27 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/09/26 13:06:21 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		~Bureaucrat(void);
		Bureaucrat(Bureaucrat const &src);

		Bureaucrat&			operator=(Bureaucrat const &src);

		int					getGrade(void) const;
		std::string			getName(void) const;
		void				incrementGrade(void);
		void				decrementGrade(void);
		void				signForm(Form &form);

	private:
		std::string	const	_name;
		int					_grade;
		void				setGrade(int grade);

	public:
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};
};

std::ostream &		operator<<(std::ostream &o, Bureaucrat const &src);

#endif
