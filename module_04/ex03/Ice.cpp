#include "Ice.hpp"

Ice::Ice(void)
{
	this->_type = "ice";
	std::cout << "[Ice] Default constructor has been called!" << std::endl;
}

Ice::~Ice()
{
	std::cout << "[Ice] Destructor has been called!" << std::endl;
}

Ice::Ice(const Ice &obj)
{
	*this = obj;
	std::cout << "[Ice] Copy constructor has been called!" << std::endl;
}

Ice &Ice::operator=(const Ice &obj)
{
	std::cout << "[Ice] Copy assignment operator has been called!" << std::endl;
	(void)obj;
	return (*this);
}

AMateria* Ice::clone() const
{
	return (new Ice());
}

void Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
