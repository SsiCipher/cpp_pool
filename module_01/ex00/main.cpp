#include "Zombie.hpp"

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

int main(void)
{
	std::string zombieName = "MONK";

	// Zombie on the stack
	// allocated and deallocated inside scope {}
	randomChump(zombieName);

	// Zombie on the heap
	Zombie *zz = newZombie(zombieName);
	zz->announce();
	delete zz;

	return (0);
}
