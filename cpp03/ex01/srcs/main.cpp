#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
	ScavTrap Jack("Jack");
	ScavTrap Paul("Paul");

	Jack.set_attackDamage(100);
	Paul.set_attackDamage(1000);

	Jack.guardGate();
	Jack.attack("Paul");
	Paul.takeDamage(Jack.get_attackDamage());

	Jack.attack("Paul");
	Paul.takeDamage(Jack.get_attackDamage());

	Paul.attack("Jack");
	Paul.beRepaired(100);

	Paul.attack("Jack");
	Paul.guardGate();
	Jack.takeDamage(Paul.get_attackDamage());

	return 0;
}
