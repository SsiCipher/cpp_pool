#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

class Weapon
{
	private:
		std::string _type;

	public:
		Weapon(void);
		Weapon(std::string type);
		~Weapon(void);
		const std::string &getType() const;
		void setType(std::string newType);
};

#endif
