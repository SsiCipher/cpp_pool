#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "[WrongAnimal] Constructor has been called!" << std::endl;
	this->_type = "";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "[WrongAnimal] Destructor has been called!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
	*this = obj;
	std::cout << "[WrongAnimal] Copy constructor has been called!" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj)
{
	std::cout << "[WrongAnimal] Copy assignment operator has been called!" << std::endl;
	if (this != &obj)
	{
		this->_type = obj._type;
	}
	return (*this);
}

const std::string&	WrongAnimal::getType() const
{
	return (this->_type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "*** 👻 Unknown animal sounds ***" << std::endl;
}
