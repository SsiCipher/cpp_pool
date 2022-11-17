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
	try
	{
		form.beSigned(*this);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

std::ostream &operator<< (std::ostream &out, const Bureaucrat &c)
{
	out << c.getName() << ", bureaucrat grade " << c.getGrade();
	return out;
}
