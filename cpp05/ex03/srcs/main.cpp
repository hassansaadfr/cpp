#include "Form.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern intern;
	Form *shruberry = intern.makeForm("shruberry creation", "Blabla");
	Form *robotomy = intern.makeForm("robotomy request", "Blabla");
	Form *presidential = intern.makeForm("presidential pardon", "Blabla");

	intern.makeForm("Blip blap", "Blabla");

	delete shruberry;
	delete robotomy;
	delete presidential;
}
