#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->_name = "";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "[ClapTrap] Default constructor has been called!" << std::endl;
}

ClapTrap::ClapTrap(std::string const &name)
{
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "[ClapTrap] Constructor has been called!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "[ClapTrap] Destructor has been called!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	std::cout << "[ClapTrap] Copy constructor has been called!" << std::endl;
	*this = obj;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
	std::cout << "[ClapTrap] Copy assignment operator has been called!" << std::endl;
	if (this != &obj)
	{
		this->_name = obj._name;
		this->_hitPoints = obj._hitPoints;
		this->_energyPoints = obj._energyPoints;
		this->_attackDamage = obj._attackDamage;
	}
	return (*this);
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints -= 1;
	}
	else
		std::cout << "ClapTrap " << this->_name << " doesn't have enough points" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " lost " << amount << " hit points" << std::endl;
		this->_hitPoints -= amount > this->_hitPoints ? this->_hitPoints : amount;
	}
	else
		std::cout << "ClapTrap " << this->_name << " doesn't have enough hit points" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " gained " << amount << " hit points back" << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints -= 1;
	}
	else
		std::cout << "ClapTrap " << this->_name << " doesn't have enough energy points" << std::endl;
}
