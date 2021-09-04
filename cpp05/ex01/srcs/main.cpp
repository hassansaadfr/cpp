#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat	michel("Michel", 1);
	Form		assedic("assedic", 3, 42);

	try
	{
		assedic.beSigned(michel);
		michel.incrementGrade();
		michel.incrementGrade();
		michel.incrementGrade();
		michel.incrementGrade();
		michel.incrementGrade();
		assedic.beSigned(michel);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}
