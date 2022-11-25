#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main(void)
{
	std::string zombieName = "MONK";

	randomChump(zombieName);

	Zombie *zz = newZombie(zombieName);
	zz->announce();
	delete zz;

	return (0);
}
