#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap	scavTrap1("scavTrap1");
	ScavTrap	scavTrap2("scavTrap2");

	scavTrap1.attack("scavTrap2");
	scavTrap2.takeDamage(20);
	scavTrap1.guardGate();
	return (0);
}
