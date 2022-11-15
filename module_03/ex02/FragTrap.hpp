#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap: public ClapTrap
{
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
