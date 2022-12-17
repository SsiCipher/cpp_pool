#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character: public ICharacter
{
	private:
		std::string		_name;
		AMateria		*_inventory[4];
		unsigned int	_inventory_size;

	public:
		Character(void);
		Character(const std::string &name);
		~Character(void);
		Character(const Character &obj);
		Character &operator=(const Character &obj);

		std::string const	&getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
};

#endif
