#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << "Shruberry Part ----------------" << std::endl;
	Bureaucrat	michel("Michel", 1);
	Bureaucrat	paul("Paul", 138);
	ShrubberyCreationForm shru("Shrubbery");
	RobotomyRequestForm	robot("Robotomy");
	PresidentialPardonForm	president("Pourtine");

	////// Shruberry part
		// No one can execute here
	michel.executeForm(shru);
	paul.executeForm(shru);
	paul.signForm(shru);

	michel.executeForm(shru);
	paul.executeForm(shru);

	// ////// Robotomy part
	// 	// No one can execute here
	michel.executeForm(robot);
	paul.executeForm(robot);

	paul.signForm(robot);

	michel.executeForm(robot);
	paul.executeForm(robot);


	// ////// Presidential part
	// 	// No one can execute here
	michel.executeForm(president);
	paul.executeForm(president);

	paul.signForm(president);

	michel.executeForm(president);
	paul.executeForm(president);

	return 0;
}
