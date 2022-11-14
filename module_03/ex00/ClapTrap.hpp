#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>

class ClapTrap
{
	private:
		std::string	name;
		int			hit_points = 10;
		int			energy_points = 10;
		int			attack_points = 0;

	public:
		ClapTrap(std::string name);
		~ClapTrap();
};

#endif
