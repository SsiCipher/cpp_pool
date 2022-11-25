#include "Zombie.hpp"

Zombie::Zombie(std::string &zombie_name)
{
	this->_name = zombie_name;
}

Zombie::~Zombie(void)
{
	std::cout << "Destroyed -> " << this->_name << "\n";
}

void Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ...\n";
}
