#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria		*_inventory[4];
		unsigned int	_inventory_size;

	public:
		MateriaSource(void);
		~MateriaSource(void);
		MateriaSource(const MateriaSource &obj);
		MateriaSource &operator=(const MateriaSource &obj);

		void		learnMateria(AMateria *);
		AMateria*	createMateria(std::string const &type);
};

#endif
