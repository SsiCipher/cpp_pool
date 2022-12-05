#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	this->_name = "nobody";
	ClapTrap::_name = "nobody_clap_name";
	this->_hitPoints = FragTrap::_intialHitPoints;
	this->_energyPoints = ScavTrap::_intialEnergyPoints;
	this->_attackDamage = FragTrap::_intialAttackDamage;
	std::cout << "[DiamondTrap] Default constructor has been called!" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name)
{
	this->_name = name;
	ClapTrap::_name = name + "_clap_name";
	this->_hitPoints = FragTrap::_intialHitPoints;
	this->_energyPoints = ScavTrap::_intialEnergyPoints;
	this->_attackDamage = FragTrap::_intialAttackDamage;
	std::cout << "[DiamondTrap] constructor has been called!" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "[DiamondTrap] Destructor has been called!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj): ClapTrap(obj), FragTrap(obj), ScavTrap(obj)
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
