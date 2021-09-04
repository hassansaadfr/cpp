#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int	main(void)
{
	int		N = 10;
	Animal	*animals = new Animal[N];

	for (size_t i = 0; i < N; i++)
	{
		if ( i % 2 == 0 )
			animals[i] = Cat();
		else
			animals[i] = Dog();
	}
	delete [] animals;


	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak
	delete i;
}
