#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string const &name)
{
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << "Constructor has been called!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor has been called!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	*this = obj;
	std::cout << "Copy constructor has been called!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
	if (this != &obj)
	{
		this->name = obj.name;
		this->hitPoints = obj.hitPoints;
		this->energyPoints = obj.energyPoints;
		this->attackDamage = obj.attackDamage;
	}
	return (*this);
}

void ClapTrap::attack(const std::string &target)
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints -= 1;
	}
	else
		std::cout << "ClapTrap " << this->name << " doesn't have enough energy points" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints > 0 && amount <= this->hitPoints)
	{
		std::cout << "ClapTrap " << this->name << " lost " << amount << " hit points" << std::endl;
		this->hitPoints -= amount;
	}
	else
		std::cout << "ClapTrap " << this->name << " doesn't have enough hit points" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " gained " << amount << " hit points back" << std::endl;
		this->hitPoints += amount;
		this->energyPoints -= 1;
	}
	else
		std::cout << "ClapTrap " << this->name << " doesn't have enough energy points" << std::endl;
}
