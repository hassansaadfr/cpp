#include "Base.hpp"

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

int	main(void)
{
	Base	*ptr = generate();
	Base	&ref = *ptr;

	std::cout << "----------------------" << std::endl;
	std::cout << "Identify with pointer" << std::endl;
	identify(ptr);
	std::cout << "----------------------" << std::endl;
	std::cout << "Identify with ref" << std::endl;
	identify(ref);
	delete ptr;
}
