#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "[WrongCat] Constructor has been called!" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::~WrongCat()
{
	std::cout << "[WrongCat] Destructor has been called!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &obj): WrongAnimal(obj)
{
	*this = obj;
	std::cout << "[WrongCat] Copy constructor has been called!" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &obj)
{
	std::cout << "[WrongCat] Copy assignment operator has been called!" << std::endl;
	if (this != &obj)
	{
		this->_type = obj._type;
	}
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "🐈 The Wrong Cat is miaowing" << std::endl;
}
