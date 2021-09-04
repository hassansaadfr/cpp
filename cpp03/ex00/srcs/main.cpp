#include <iostream>
#include "ClapTrap.hpp"

int main(void) {
	ClapTrap Jack("Jack");
	ClapTrap Paul("Paul");

	Jack.set_attackDamage(10);
	Paul.set_attackDamage(100);

	Jack.attack("Paul");
	Paul.takeDamage(Jack.get_attackDamage());

	Jack.attack("Paul");
	Paul.takeDamage(Jack.get_attackDamage());

	Paul.attack("Jack");
	Paul.beRepaired(10);

	Paul.attack("Jack");
	Jack.takeDamage(Paul.get_attackDamage());
	return 0;
}
