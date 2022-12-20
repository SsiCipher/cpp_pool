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
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw Form::GradeTooLowException();
	this->_isSigned = false;
}

Form::~Form()
{
	std::cout << "[Form] Destructor has been called!" << std::endl;
}

Form::Form(const Form &obj): _name(obj._name), _gradeToSign(obj._gradeToSign), _gradeToExec(obj._gradeToExec)
{
	std::cout << "[Form] Copy constructor has been called!" << std::endl;
	*this = obj;
}

Form &Form::operator=(const Form &obj)
{
	std::cout << "[Form] Copy assignment operator has been called!" << std::endl;
	this->_isSigned = obj._isSigned;
	return (*this);
}

std::string	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getIsSigned(void) const
{
	return (this->_isSigned);
}

unsigned short	Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

unsigned short	Form::getGradeToExec(void) const
{
	return (this->_gradeToExec);
}

void	Form::beSigned(const Bureaucrat &him)
{
	if (him.getGrade() <= this->getGradeToSign())
		this->_isSigned = true;
	else
		throw Form::GradeTooLowException();
}

const char * Form::GradeTooLowException::what() const throw ()
{
	return "The given grade is too low";
}

const char * Form::GradeTooHighException::what() const throw ()
{
	return "The given grade is too high";
}

std::ostream &operator<< (std::ostream &stream, const Form &obj)
{
	stream << "Form [ " << obj.getName() << " ] " << std::endl;
	stream << "    is " << (obj.getIsSigned() ? "signed ✅" : "not signed ❌") << std::endl;
	stream << "    Grade to sign: " << obj.getGradeToSign() << std::endl;
	stream << "    Grade to execute: " << obj.getGradeToExec();
	return (stream);
}
