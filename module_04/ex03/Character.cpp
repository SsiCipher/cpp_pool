#include "Character.hpp"

Character::Character(void)
{
	std::cout << "[Character] Default constructor has been called!" << std::endl;
}

Character::~Character()
{
	std::cout << "[Character] Destructor has been called!" << std::endl;
}

Character::Character(const Character &obj)
{
	*this = obj;
	std::cout << "[Character] Copy constructor has been called!" << std::endl;
}

Character &Character::operator=(const Character &obj)
{
	std::cout << "[Character] Copy assignment operator has been called!" << std::endl;
	if (this != &obj)
	{
	}
	return (*this);
}
