#ifndef HUMAN_A_H
#define HUMAN_A_H

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
private:
	Weapon weapon;
	std::string name;

public:
	HumanA(Weapon &Weapon);

	void attack();
};

#endif
