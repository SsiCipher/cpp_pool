#include "Zombie.hpp"

Zombie::Zombie(std::string &zombie_name)
{
	name = zombie_name;
}

Zombie::~Zombie(void)
{
	std::cout << "Destroyed -> " << name << "\n";
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}