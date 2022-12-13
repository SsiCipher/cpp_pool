#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	std::cout << "[MateriaSource] Default constructor has been called!" << std::endl;
	this->_inventory_size = 0;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	std::cout << "[MateriaSource] Destructor has been called!" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource &obj)
{
	std::cout << "[MateriaSource] Copy constructor has been called!" << std::endl;
	*this = obj;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &obj)
{
	std::cout << "[MateriaSource] Copy assignment operator has been called!" << std::endl;
	if (this != &obj)
	{
		this->_inventory_size = obj._inventory_size;
		for (int i = 0; i < 4; i++){
			if (this->_inventory[i])
				delete this->_inventory[i];
		}
		for (int i = 0; i < 4; i++)
		{
			if (obj._inventory[i])
				this->_inventory[i] = obj._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	return (*this);
}

void			MateriaSource::learnMateria(AMateria *m)
{
	bool materia_equiped = false;

	for (int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			this->_inventory_size += 1;
			materia_equiped = true;
			break;
		}
	}
	if (!materia_equiped)
		std::cout << "Inventory is full" << std::endl;
}

AMateria*	MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i]->getType() == type)
			return (this->_inventory[i]->clone());
	}
	return (NULL);
}
