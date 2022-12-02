#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap cp1("cp1");
	ClapTrap cp2("cp2");

	cp1.attack("cp2");
	cp2.takeDamage(2);
	cp2.beRepaired(2);

	return (0);
}
