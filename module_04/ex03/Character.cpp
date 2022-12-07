#include "Character.hpp"

Character::Character(void)
{
	std::cout << "[Character] Default constructor has been called!" << std::endl;
	this->_name = "";
	this->_inventory_size = 0;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const std::string &name)
{
	std::cout << "[Character] Constructor has been called!" << std::endl;
	this->_name = name;
	this->_inventory_size = 0;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::~Character()
{
	std::cout << "[Character] Destructor has been called!" << std::endl;
	for (int i = 0; i < 4; i++){
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

Character::Character(const Character &obj)
{
	std::cout << "[Character] Copy constructor has been called!" << std::endl;
	*this = obj;
}

Character &Character::operator=(const Character &obj)
{
	std::cout << "[Character] Copy assignment operator has been called!" << std::endl;
	if (this != &obj)
	{
		this->_name = obj._name;
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

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
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
		std::cout << "Character " << this->_name << "'s inventory is full" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		std::cout << "The index can't be out of the range 0-3" << std::endl;
	else if (!this->_inventory[idx])
		std::cout << "There is no materia at index " << idx << std::endl;
	else
	{
		delete this->_inventory[idx];
		this->_inventory[idx] = NULL;
		this->_inventory_size -= 1;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		std::cout << "The index can't be out of the range 0-3" << std::endl;
	else if (!this->_inventory[idx])
		std::cout << "There is no materia at index " << idx << std::endl;
	else
		this->_inventory[idx]->use(target);
}
