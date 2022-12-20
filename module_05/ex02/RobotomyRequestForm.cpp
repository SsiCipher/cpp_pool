#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): Form("robotomy request", 72, 45)
{
	std::cout << "[RobotomyRequestForm] Default constructor has been called!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target): Form("robotomy request", 72, 45)
{
	std::cout << "[RobotomyRequestForm] Constructor has been called!" << std::endl;
	this->_target = target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "[RobotomyRequestForm] Destructor has been called!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj): Form(obj)
{
	std::cout << "[RobotomyRequestForm] Copy constructor has been called!" << std::endl;
	*this = obj;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
	std::cout << "[RobotomyRequestForm] Copy assignment operator has been called!" << std::endl;
	this->Form::operator=(obj);
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (this->getIsSigned() && executor.getGrade() <= this->getGradeToExec())
	{
		std::cout << "* LOUD DRILLING NOISE *" << std::endl;
		if (time(0) % 10 > 5)
			std::cout << this->_target << " has been robotomized" << std::endl;
		else
			std::cout << "the robotomy failed" << std::endl;
	}
	else
		throw Form::GradeTooLowException();
}
