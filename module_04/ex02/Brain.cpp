#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "[Brain] Constructor has been called!" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "~ VOID ~";
}

Brain::~Brain()
{
	std::cout << "[Brain] Destructor has been called!" << std::endl;
}

Brain::Brain(const Brain &obj)
{
	std::cout << "[Brain] Copy constructor has been called!" << std::endl;
	*this = obj;
}

Brain &Brain::operator=(const Brain &obj)
{
	std::cout << "[Brain] Copy assignment operator has been called!" << std::endl;
	if (this != &obj)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = obj._ideas[i];
	}
	return (*this);
}
