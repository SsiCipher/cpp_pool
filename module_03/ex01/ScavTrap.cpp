#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	this->_name = "";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "[ScavTrap] Default constructor has been called!" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "[ScavTrap] constructor has been called!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "[ScavTrap] Destructor has been called!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &obj): ClapTrap(obj)
{
	*this = obj;
	std::cout << "[ScavTrap] Copy constructor has been called!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &obj)
{
	std::cout << "[ScavTrap] Copy assignment operator has been called!" << std::endl;
	if (this != &obj)
	{
		this->_name = obj._name;
		this->_hitPoints = obj._hitPoints;
		this->_energyPoints = obj._energyPoints;
		this->_attackDamage = obj._attackDamage;
	}
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints -= 1;
	}
	else
		std::cout << "ScavTrap " << this->_name << " doesn't have enough energy points" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap is in gate keeper mode" << std::endl;
}
