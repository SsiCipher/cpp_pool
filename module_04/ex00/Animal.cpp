#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "[Animal] Constructor has been called!" << std::endl;
	this->_type = "";
}

Animal::~Animal()
{
	std::cout << "[Animal] Destructor has been called!" << std::endl;
}

Animal::Animal(const Animal &obj)
{
	*this = obj;
	std::cout << "[Animal] Copy constructor has been called!" << std::endl;
}

Animal &Animal::operator=(const Animal &obj)
{
	std::cout << "[Animal] Copy assignment operator has been called!" << std::endl;
	if (this != &obj)
	{
		this->_type = obj._type;
	}
	return (*this);
}

const std::string&	Animal::getType() const
{
	return (this->_type);
}

void	Animal::makeSound() const
{
	std::cout << "*** 👻 Unknown animal sounds ***" << std::endl;
}
