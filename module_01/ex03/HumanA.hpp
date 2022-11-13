#ifndef HUMAN_A_H
#define HUMAN_A_H

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string	name;
		Weapon		&weapon;

	public:
		HumanA(std::string human_name, Weapon human_weapon);
		~HumanA(void);
		void	attack(void);
};

#endif
