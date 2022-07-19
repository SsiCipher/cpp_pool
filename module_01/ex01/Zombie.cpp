#include "Zombie.hpp"

Zombie::Zombie(void)
{
}

Zombie::Zombie(std::string &zombie_name)
{
	this->name = zombie_name;
}

Zombie::~Zombie(void)
{
	std::cout << "Destroyed -> " << this->name << "\n";
}

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(std::string &name)
{
	this->name = name;
}
