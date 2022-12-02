#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): ClapTrap(), FragTrap(), ScavTrap()
{
	this->_name = "nobody";
	ClapTrap::_name = "nobody_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "[DiamondTrap] Default constructor has been called!" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name): ClapTrap(name), FragTrap(name), ScavTrap(name)
{
	this->_name = name;
	ClapTrap::_name = name + "_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "[DiamondTrap] constructor has been called!" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "[DiamondTrap] Destructor has been called!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj)
{
	std::cout << "[DiamondTrap] Copy constructor has been called!" << std::endl;
	*this = obj;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &obj)
{
	std::cout << "[DiamondTrap] Copy assignment operator has been called!" << std::endl;
	if (this != &obj)
	{
		this->_name = obj._name;
		ClapTrap::_name = obj.ClapTrap::_name;
		this->_hitPoints = obj.FragTrap::_hitPoints;
		this->_energyPoints = obj.ScavTrap::_energyPoints;
		this->_attackDamage = obj.FragTrap::_attackDamage;
	}
	return (*this);
}

void DiamondTrap::attack(const std::string &target)
{
	this->ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "Name: " << this->_name << ", ClapTrap name: " << this->ClapTrap::_name << std::endl;
}

std::ostream& operator<<(std::ostream& os, const DiamondTrap& dt)
{
	os << dt._name << " - " << dt.ClapTrap::_name << " - " << dt._hitPoints << " - " << dt._energyPoints << " - " << dt._attackDamage;
	return (os);
}
