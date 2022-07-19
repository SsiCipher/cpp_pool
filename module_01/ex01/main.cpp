#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int main(void)
{
	std::string zombieName = "ZOMO";
	std::string newZombieName = "ZOMI";

	Zombie *horde = zombieHorde(3, zombieName);

	horde->setName(newZombieName);
	for (int i = 0; i < 3; i++)
		horde[i].announce();

	delete[] horde;

	return (0);
}
