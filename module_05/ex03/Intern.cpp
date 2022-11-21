#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "[Intern] Default constructor has been called!" << std::endl;
}

Intern::~Intern(void)
{
	std::cout << "[Intern] Destructor has been called!" << std::endl;
}

Intern::Intern(const Intern &obj)
{
	*this = obj;
	std::cout << "[Intern] Copy constructor has been called!" << std::endl;
}

Intern &Intern::operator=(const Intern &obj)
{
	std::cout << "[Intern] Copy assignment operator has been called!" << std::endl;
	if (this != &obj)
	{
	}
	return (*this);
}

Form *Intern::makeForm(std::string& formName, std::string& target)
{
	Form *form;

	if (formName == "presidential pardon")
		form = new PresidentialPardonForm(target);
	else if (formName == "robotomy request")
		form = new RobotomyRequestForm(target);
	else if (formName == "shrubbery creation")
		form = new ShrubberyCreationForm(target);
	else
	{
		std::cout << "The given Form name is invalid!" << std::endl;
		return (NULL);
	}
	std::cout << "Intern creates " << formName << std::endl;
	return (form);
}
