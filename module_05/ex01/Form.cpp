#include "Form.hpp"

Form::Form(void): _name(""), _gradeToSign(150), _gradeToExec(150)
{
	std::cout << "[Form] Default constructor has been called!" << std::endl;
	this->_isSigned = false;
}

Form::Form(const std::string name, const unsigned short gradeToSign, const unsigned short gradeToExec)
	: _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	std::cout << "[Form] Constructor has been called!" << std::endl;
	if (gradeToSign < 1 || gradeToExec < 1)
		throw Form::GradeTooHighException;
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw Form::GradeTooLowException;
	this->_isSigned = false;
}

Form::~Form()
{
	std::cout << "[Form] Destructor has been called!" << std::endl;
}

Form::Form(const Form &obj): _name(obj._name), _gradeToSign(obj._gradeToSign), _gradeToExec(obj._gradeToExec)
{
	*this = obj;
	std::cout << "[Form] Copy constructor has been called!" << std::endl;
}

Form &Form::operator=(const Form &obj)
{
	std::cout << "[Form] Copy assignment operator has been called!" << std::endl;
	if (this != &obj)
	{
		this->_isSigned = obj._isSigned;
	}
	return (*this);
}

const char * Form::LowException::what() const throw ()
{
	return "The given grade is too low";
}

const char * Form::HighException::what() const throw ()
{
	return "The given grade is too high";
}

const std::string	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getIsSigned(void) const
{
	return (this->_isSigned);
}

const unsigned short	Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

const unsigned short	Form::getGradeToExec(void) const
{
	return (this->_gradeToExec);
}

void	Form::beSigned(const Bureaucrat &him)
{
	if (him.getGrade() <= this->getGradeToSign())
		this->_isSigned = false;
	else
		throw Form::GradeTooLowException;
}

std::ostream &operator<< (std::ostream &stream, const Form &obj)
{
	stream << "Form [ " << obj.getName() << " ] " << std::endl;
	stream << "\tIs signed: " << obj.getIsSigned() << std::endl;
	stream << "\tGrade to sign: " << obj.getGradeToSign() << std::endl;
	stream << "\tGrade to execute: " << obj.getGradeToExec() << std::endl;
	return (stream);
}
