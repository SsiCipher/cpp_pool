#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap: virtual public ClapTrap
{
	protected:
		static const int _intialHitPoints = 100;
		static const int _intialEnergyPoints = 100;
		static const int _intialAttackDamage = 30;

	public:
		FragTrap(void);
		FragTrap(std::string name);
		~FragTrap(void);
		FragTrap(const FragTrap &obj);
		FragTrap &operator=(const FragTrap &obj);

		void attack(const std::string &target);
		void highFivesGuys(void);
};

#endif
