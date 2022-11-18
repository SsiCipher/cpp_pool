#include "AMateria.hpp"

AMateria::AMateria(void)
{
	std::cout << "[AMateria] Constructor has been called!" << std::endl;
	this->_type = "";
}

AMateria::AMateria(std::string const &type)
{
	std::cout << "[AMateria] Constructor has been called!" << std::endl;
	this->_type = type;
}

AMateria::~AMateria()
{
	std::cout << "[AMateria] Destructor has been called!" << std::endl;
}

AMateria::AMateria(const AMateria &obj)
{
	*this = obj;
	std::cout << "[AMateria] Copy constructor has been called!" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &obj)
{
	std::cout << "[AMateria] Copy assignment operator has been called!" << std::endl;
	if (this != &obj)
	{
		this->_type = obj._type;
	}
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << target.getName() << " is being used" << std::endl;
}
