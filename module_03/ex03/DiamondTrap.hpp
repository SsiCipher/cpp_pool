#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
	private:
		std::string		_name;

	public:
		DiamondTrap(void);
		DiamondTrap(const std::string &name);
		~DiamondTrap(void);
		DiamondTrap(const DiamondTrap &obj);
		DiamondTrap &operator=(const DiamondTrap &obj);

		void attack(const std::string &target);
		void whoAmI();

		friend std::ostream& operator<<(std::ostream& os, const DiamondTrap& dt);
};

std::ostream& operator<<(std::ostream& os, const DiamondTrap& dt);

#endif
