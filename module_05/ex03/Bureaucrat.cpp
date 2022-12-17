#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("")
{
	std::cout << "[Bureaucrat] Default constructor has been called!" << std::endl;
	this->_grade = 150;
}

Bureaucrat::Bureaucrat(const std::string &name, unsigned short grade): _name(name)
{
	std::cout << "[Bureaucrat] Constructor has been called!" << std::endl;
	if (grade < 1)
		throw Bureaucrat::_GradeTooHighException;
	else if (grade > 150)
		throw Bureaucrat::_GradeTooLowException;
	else
		this->_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "[Bureaucrat] Destructor has been called!" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj): _name(obj._name)
{
	std::cout << "[Bureaucrat] Copy constructor has been called!" << std::endl;
	*this = obj;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
	std::cout << "[Bureaucrat] Copy assignment operator has been called!" << std::endl;
	if (this != &obj)
	{
		this->_grade = obj._grade;
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
	return (this->_name);
}

unsigned short	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade()
{
	if (this->_grade == 1)
		throw Bureaucrat::_GradeTooHighException;
	else
		this->_grade -= 1;
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade == 150)
		throw Bureaucrat::_GradeTooLowException;
	else
		this->_grade += 1;
}

void	Bureaucrat::signForm(const Form &form)
{
	if (this->_grade <= form.getGradeToSign())
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	else
		std::cout << this->_name << " couldn't sign "<< form.getName() << " because the bureaucrats grade low" << std::endl;
}

std::ostream &operator<< (std::ostream &out, const Bureaucrat &c)
{
	out << c.getName() << ", bureaucrat grade " << c.getGrade();
	return out;
}
