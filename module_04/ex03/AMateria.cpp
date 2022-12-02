#include "AMateria.hpp"

AMateria::AMateria(void)
{
	this->_type = "";
	std::cout << "[AMateria] Default constructor has been called!" << std::endl;
}

AMateria::AMateria(std::string const & type)
{
	this->_type = type;
	std::cout << "[AMateria] constructor has been called!" << std::endl;
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

std::string const &AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "Using materia " << this->_type << " by " << target.getName() << std::endl;
}
