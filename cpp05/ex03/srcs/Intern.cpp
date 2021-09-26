#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void)
{}

Intern::~Intern(void)
{}

Intern::Intern(Intern const &src)
{
	*this = src;
}

Intern&	Intern::operator=(Intern const &src)
{
	if (this != &src)
	{}
	return *this;
}


typedef Form* Creator(std::string target);
template < typename Cls >
Form	*create(std::string target)
{
	return new Cls(target);
}

Form*	Intern::makeForm(std::string const name, std::string const target) const
{
	std::string	allowed[3] = {
		"robotomy request", "shruberry creation", "presidential pardon"
	};

	Creator*	fun[3] = {
		create<ShrubberyCreationForm>,
		create<RobotomyRequestForm>,
		create<PresidentialPardonForm>
	};

	for (size_t i = 0; i < 3; i++)
	{
		if (allowed[i] == name)
		{
			Form *out = fun[i](target);
			std::cout << "intern create " << out->getName() << std::endl;
			return out;
		}
	}
	std::cerr << "Cant find the form specified" << std::endl;
	return (__null);
}

std::ostream &	operator<<(std::ostream &o, Intern const &src)
{
	o << "Hi i'm an Intern my address is " << &src;
	return o;
}
