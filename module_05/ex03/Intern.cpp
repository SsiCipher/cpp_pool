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
	std::cout << "[Intern] Copy constructor has been called!" << std::endl;
	*this = obj;
}

Intern &Intern::operator=(const Intern &obj)
{
	std::cout << "[Intern] Copy assignment operator has been called!" << std::endl;
	(void)obj;
	return (*this);
}

const char *Intern::InternException::what() const throw()
{
	return ("The given Form name is invalid!");
}

Form *Intern::makeForm(const std::string& formName, const std::string& target)
{
	Form *form;
	int formIndex = (
		(formName == "presidential pardon") * 1
		+ (formName == "robotomy request") * 2
		+ (formName == "shrubbery creation") * 3
	);

	switch (formIndex)
	{
		case 1:
			form = new PresidentialPardonForm(target);
			break;
		case 2:
			form = new RobotomyRequestForm(target);
			break;
		case 3:
			form = new ShrubberyCreationForm(target);
			break;
		default:
			std::cout << "The given Form name is invalid!" << std::endl;
			throw Intern::InternException();
			break;
	}
	std::cout << "Intern creates " << formName << std::endl;
	return (form);
}
