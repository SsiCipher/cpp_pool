#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main(void)
{
	randomChump("Zomb1");

	Zombie *zz = newZombie("Zomb2");
	zz->announce();
	delete zz;

	return (0);
}
