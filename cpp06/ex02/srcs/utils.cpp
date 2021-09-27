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
	try
	{
		A* a = dynamic_cast<A*>(&p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		B* b = dynamic_cast<B*>(&p);
		std::cout << "b" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		C* c = dynamic_cast<C*>(&p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "Cant identify type" << std::endl;
}
