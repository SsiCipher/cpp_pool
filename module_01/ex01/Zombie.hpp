#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie
{
private:
	std::string name;

public:
	Zombie(void);
	Zombie(std::string &zombie_name);
	~Zombie(void);

	void announce(void);
	void setName(std::string &name);
};

#endif
