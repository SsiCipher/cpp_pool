#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clapTrap1("clapTrap1");
	ClapTrap clapTrap2("clapTrap2");

	clapTrap1.attack("clapTrap2");
	clapTrap2.takeDamage(0);
	clapTrap2.beRepaired(1);
	return (0);
}
