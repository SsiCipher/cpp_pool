#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("shrubbery creation", 145, 137)
{
	std::cout << "[ShrubberyCreationForm] Default constructor has been called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : Form("shrubbery creation", 145, 137)
{
	std::cout << "[ShrubberyCreationForm] Constructor has been called!" << std::endl;
	this->_target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "[ShrubberyCreationForm] Destructor has been called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : Form(obj)
{
	std::cout << "[ShrubberyCreationForm] Copy constructor has been called!" << std::endl;
	*this = obj;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
	std::cout << "[ShrubberyCreationForm] Copy assignment operator has been called!" << std::endl;
	this->Form::operator=(obj);
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned() && executor.getGrade() <= this->getGradeToExec())
	{
		std::ofstream shrubberyFile;

		shrubberyFile.open(this->_target + "_shrubbery");
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
			shrubberyFile << "__._ \\/ ._\\//_/__/  ,\\_//__\\_/.  \\_//__/_" << std::endl;
		}
		shrubberyFile.close();
	}
	else
		throw Form::GradeTooLowException();
}
