#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void): Form("", 145, 137)
{
	std::cout << "[ShrubberyCreationForm] Default constructor has been called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): Form(target, 145, 137)
{
	std::cout << "[ShrubberyCreationForm] Constructor has been called!" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "[ShrubberyCreationForm] Destructor has been called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj): Form(obj)
{
	*this = obj;
	std::cout << "[ShrubberyCreationForm] Copy constructor has been called!" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
	std::cout << "[ShrubberyCreationForm] Copy assignment operator has been called!" << std::endl;
	if (this != &obj)
	{
		this->_isSigned = obj._isSigned;
	}
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (this->getIsSigned() && executor.getGrade() <= this->getGradeToExec())
	{
		std::ofstream shrubberyFile;

		shrubberyFile.open(this->getName() + "_shrubbery");
		if (!shrubberyFile.is_open())
		{
			std::cout << "ERROR: Failed to create the file" << std::endl;
			return;
		}
		else
		{
			shrubberyFile << "               ,@@@@@@@," << std::endl;
			shrubberyFile << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
			shrubberyFile << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
			shrubberyFile << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
			shrubberyFile << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
			shrubberyFile << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
			shrubberyFile << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
			shrubberyFile << "       |o|        | |         | |" << std::endl;
			shrubberyFile << "       |.|        | |         | |" << std::endl;
			shrubberyFile << "jgs \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
		}
	}
	else
		throw ShrubberyCreationForm::GradeTooLowException;
}
