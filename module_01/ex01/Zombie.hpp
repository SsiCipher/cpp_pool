#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie
{
	private:
		std::string _name;

	public:
		Zombie(void);
		Zombie(std::string &zombie_name);
		~Zombie(void);

		void announce(void);
		void setName(const std::string &name);
};

#endif
