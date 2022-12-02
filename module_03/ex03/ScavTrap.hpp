#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap: virtual public ClapTrap
{
	protected:
		static const int _intialHitPoints = 100;
		static const int _intialEnergyPoints = 50;
		static const int _intialAttackDamage = 20;

	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		~ScavTrap(void);
		ScavTrap(const ScavTrap &obj);
		ScavTrap &operator=(const ScavTrap &obj);

		void attack(const std::string &target);
		void guardGate();
};

#endif
