#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "[Cat] Constructor has been called!" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::~Cat()
{
	std::cout << "[Cat] Destructor has been called!" << std::endl;
	delete this->_brain;
}

Cat::Cat(const Cat &obj): Animal(obj), _brain(NULL)
{
	std::cout << "[Cat] Copy constructor has been called!" << std::endl;
	*this = obj;
}

Cat &Cat::operator=(const Cat &obj)
{
	std::cout << "[Cat] Copy assignment operator has been called!" << std::endl;
	if (this != &obj)
	{
		if(_brain)
			delete _brain;
		this->_type = obj._type;
		this->_brain = new Brain();
		*(this->_brain) = *(obj._brain);
	}
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "🐈 The cat is miaowing" << std::endl;
}
