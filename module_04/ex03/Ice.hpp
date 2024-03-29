#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

class Ice: public AMateria
{
	public:
		Ice(void);
		~Ice(void);
		Ice(const Ice &obj);
		Ice &operator=(const Ice &obj);

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
