#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character: public ICharacter
{
	private:
		AMateria	inventory[4];

	public:
		Character(void);
		~Character(void);
		Character(const Character &obj);
		Character &operator=(const Character &obj);
};

#endif
