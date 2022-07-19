#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie
{
	private:
		std::string name;

	public:
		Zombie(std::string &zombie_name)
		{
			name = zombie_name;
		}

		~Zombie(void)
		{
			std::cout << "Destroyed -> " << name << "\n";
		}

		void	announce(void)
		{
			std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
		}
};

#endif
