#ifndef HUMAN_B_H
#define HUMAN_B_H

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		Weapon *weapon;

	public:
		HumanB(std::string human_name);
		~HumanB();

		void attack(void);
		void setWeapon(Weapon &human_weapon);
};

#endif
