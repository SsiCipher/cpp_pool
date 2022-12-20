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
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
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
	this->_grade = obj._grade;
	return (*this);
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
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade -= 1;
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
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

void	Bureaucrat::executeForm(Form const &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->_name << " coudn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "The given grade is too low";
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "The given grade is too high";
}

std::ostream &operator<< (std::ostream &out, const Bureaucrat &c)
{
	out << c.getName() << ", bureaucrat grade " << c.getGrade();
	return out;
}
