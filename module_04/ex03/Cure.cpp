#include "Cure.hpp"

Cure::Cure(void)
{
	this->_type = "cure";
	std::cout << "[Cure] Default constructor has been called!" << std::endl;
}

Cure::~Cure()
{
	std::cout << "[Cure] Destructor has been called!" << std::endl;
}

Cure::Cure(const Cure &obj)
{
	*this = obj;
	std::cout << "[Cure] Copy constructor has been called!" << std::endl;
}

Cure &Cure::operator=(const Cure &obj)
{
	std::cout << "[Cure] Copy assignment operator has been called!" << std::endl;
	(void)obj;
	return (*this);
}

AMateria* Cure::clone() const
{
	return (new Cure());
}

void Cure::use(ICharacter& target){
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
