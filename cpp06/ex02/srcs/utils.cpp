#include "Base.hpp"
#include "stdlib.h"

Base	*generate(void)
{
	int		n;
	srand(time(0));
	n = rand() % 3 + 1;
	if (n == 1)
		return new A();
	if (n == 2)
		return new B();
	return new C();
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Cant identify type" << std::endl;
}

void	identify(Base &p)
{
	if (dynamic_cast<A*>(&p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(&p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(&p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Cant identify type" << std::endl;
}
