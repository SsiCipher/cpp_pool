#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "[Cat] Constructor has been called!" << std::endl;
	this->_type = "Cat";
}

Cat::~Cat()
{
	std::cout << "[Cat] Destructor has been called!" << std::endl;
}

Cat::Cat(const Cat &obj): Animal(obj)
{
	std::cout << "[Cat] Copy constructor has been called!" << std::endl;
	*this = obj;
}

Cat &Cat::operator=(const Cat &obj)
{
	std::cout << "[Cat] Copy assignment operator has been called!" << std::endl;
	if (this != &obj)
	{
		this->_type = obj._type;
	}
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "🐈 The cat is miaowing" << std::endl;
}
