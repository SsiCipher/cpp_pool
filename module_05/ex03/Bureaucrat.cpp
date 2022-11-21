#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("")
{
	std::cout << "[Bureaucrat] Default constructor has been called!" << std::endl;
	this->grade = 150;
}

Bureaucrat::Bureaucrat(const std::string name, unsigned short grade): name(name)
{
	std::cout << "[Bureaucrat] Constructor has been called!" << std::endl;
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

Bureaucrat::Bureaucrat(const Bureaucrat &obj): name(obj.name)
{
	std::cout << "[Bureaucrat] Copy constructor has been called!" << std::endl;
	*this = obj;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
	std::cout << "[Bureaucrat] Copy assignment operator has been called!" << std::endl;
	if (this != &obj)
	{
		this->grade = obj.grade;
	}
	return (*this);
}

const char *Bureaucrat::LowException::what() const throw()
{
	return "The given grade is too low";
}

const char *Bureaucrat::HighException::what() const throw()
{
	return "The given grade is too high";
}

const std::string	Bureaucrat::getName() const
{
	return (this->name);
}

unsigned short	Bureaucrat::getGrade() const
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

void	Bureaucrat::signForm(const Form &form)
{
	if (this->grade <= form.getGradeToSign())
		std::cout << this->name << " signed " << form.getName() << std::endl;
	else
		std::cout << this->name << " couldn't sign "<< form.getName() << " because the bureaucrats grade low" << std::endl;
}

void	Bureaucrat::executeForm(Form const &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

std::ostream &operator<< (std::ostream &out, const Bureaucrat &c)
{
	out << c.getName() << ", bureaucrat grade " << c.getGrade();
	return out;
}
