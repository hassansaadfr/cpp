/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 13:39:27 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/09/03 17:36:27 by hsaadaou         ###   ########.fr       */
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
		void				executeForm (Form const & form);
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
