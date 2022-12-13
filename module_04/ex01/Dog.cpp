#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "[Dog] Constructor has been called!" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::~Dog()
{
	std::cout << "[Dog] Destructor has been called!" << std::endl;
	delete this->_brain;
}

Dog::Dog(const Dog &obj): Animal(obj)
{
	std::cout  << "[Dog] Copy constructor has been called!" << std::endl;
	*this = obj;
}

Dog &Dog::operator=(const Dog &obj)
{
	std::cout << "[Dog] Copy assignment operator has been called!" << std::endl;
	if (this != &obj)
	{
		this->_type = obj._type;
		this->_brain = new Brain();
		*(this->_brain) = *(obj._brain);
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "🐕 The dog is barking" << std::endl;
}
