#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	this->_name = "";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "[FragTrap] Default constructor has been called!" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "[FragTrap] constructor has been called!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "[FragTrap] Destructor has been called!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &obj): ClapTrap(obj)
{
	*this = obj;
	std::cout << "[FragTrap] Copy constructor has been called!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &obj)
{
	std::cout << "[FragTrap] Copy assignment operator has been called!" << std::endl;
	if (this != &obj)
	{
		this->_name = obj._name;
		this->_hitPoints = obj._hitPoints;
		this->_energyPoints = obj._energyPoints;
		this->_attackDamage = obj._attackDamage;
	}
	return (*this);
}

void	FragTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints -= 1;
	}
	else
		std::cout << "FragTrap " << this->_name << " doesn't have enough energy points" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap is looking for ✋ high fives" << std::endl;
}
