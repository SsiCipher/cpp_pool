#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): Form("", 145, 137)
{
	std::cout << "[RobotomyRequestForm] Default constructor has been called!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target): Form(target, 72, 45)
{
	std::cout << "[RobotomyRequestForm] Constructor has been called!" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "[RobotomyRequestForm] Destructor has been called!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj): Form(obj)
{
	*this = obj;
	std::cout << "[RobotomyRequestForm] Copy constructor has been called!" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
	std::cout << "[RobotomyRequestForm] Copy assignment operator has been called!" << std::endl;
	if (this != &obj)
	{
		this->_isSigned = obj._isSigned;
	}
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (this->getIsSigned() && executor.getGrade() <= this->getGradeToExec())
	{
		std::cout << "* LOUD DRILLING NOISE *" << std::endl;
		if (time(0) % 100 > 50)
			std::cout << this->getName() << " has been robotomized" << std::endl;
		else
			std::cout << "the robotomy failed" << std::endl;
	}
	else
		throw RobotomyRequestForm::GradeTooLowException;
}
