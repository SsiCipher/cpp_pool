#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, unsigned short grade)
{
	std::cout << "[Bureaucrat] Constructor has been called!" << std::endl;
	this->name = name;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException;
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException;
	else
		this->grade = grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "[Bureaucrat] Destructor has been called!" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{
	*this = obj;
	std::cout << "[Bureaucrat] Copy constructor has been called!" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
	std::cout << "[Bureaucrat] Copy assignment operator has been called!" << std::endl;
	if (this != &obj)
	{
		this->name = obj.name;
		this->grade = obj.grade;
	}
	return (*this);
}

std::string	Bureaucrat::getName()
{
	return (this->name);
}

unsigned short	Bureaucrat::getGrade()
{
	return (this->grade);
}

void	Bureaucrat::incrementGrade()
{
	if (this->grade == 1)
		throw Bureaucrat::GradeTooHighException;
	else
		this->grade -= 1;
}

void	Bureaucrat::decrementGrade()
{
	if (this->grade == 150)
		throw Bureaucrat::GradeTooLowException;
	else
		this->grade += 1;
}
