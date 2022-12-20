#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): Form("presidential pardon", 25, 5)
{
	std::cout << "[PresidentialPardonForm] Default constructor has been called!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target): Form("presidential pardon", 25, 5)
{
	std::cout << "[PresidentialPardonForm] Constructor has been called!" << std::endl;
	this->_target = target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "[PresidentialPardonForm] Destructor has been called!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj)
{
	std::cout << "[PresidentialPardonForm] Copy constructor has been called!" << std::endl;
	*this = obj;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
	std::cout << "[PresidentialPardonForm] Copy assignment operator has been called!" << std::endl;
	this->Form::operator=(obj);
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (this->getIsSigned() && executor.getGrade() <= this->getGradeToExec())
		std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	else
		throw Form::GradeTooLowException();
}
