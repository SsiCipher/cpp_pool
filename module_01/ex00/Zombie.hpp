#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie
{
	private:
		std::string	_name;

	public:
		Zombie(std::string &zombie_name);
		~Zombie(void);

		void announce(void);
};

#endif
