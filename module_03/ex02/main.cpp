#include "FragTrap.hpp"

int main(void)
{
	FragTrap	fragTrap1("fragTrap1");
	FragTrap	fragTrap2("fragTrap2");

	fragTrap1.attack("fragTrap2");
	fragTrap2.takeDamage(20);
	fragTrap1.highFivesGuys();

	return (0);
}
