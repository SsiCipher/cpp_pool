#include "ClapTrap.hpp"

int main(void)
{
	std::string clapTrap1Name = "Srghini";
	std::string clapTrap2Name = "Hmed Lkatourza";

	ClapTrap clapTrap1(clapTrap1Name);
	ClapTrap clapTrap2(clapTrap2Name);

	clapTrap1.attack(clapTrap2Name);
	clapTrap2.takeDamage(10);
	clapTrap2.takeDamage(10);
	clapTrap2.beRepaired(10);
	clapTrap2.takeDamage(10);

	return (0);
}
