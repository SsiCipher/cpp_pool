#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): Form("", 25, 5)
{
	std::cout << "[PresidentialPardonForm] Default constructor has been called!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target): Form(target, 25, 5)
{
	std::cout << "[PresidentialPardonForm] Constructor has been called!" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "[PresidentialPardonForm] Destructor has been called!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj)
{
	*this = obj;
	std::cout << "[PresidentialPardonForm] Copy constructor has been called!" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
	std::cout << "[PresidentialPardonForm] Copy assignment operator has been called!" << std::endl;
	if (this != &obj)
	{
		this->_isSigned = obj._isSigned;
	}
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (this->getIsSigned() && executor.getGrade() <= this->getGradeToExec())
		std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	else
		throw PresidentialPardonForm::GradeTooLowException;
}
