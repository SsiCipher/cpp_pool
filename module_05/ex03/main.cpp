#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	// Bureaucrat president("Donald Trump", 20);
	// RobotomyRequestForm form("home");
	Intern dumbIntern;

	try
	{
		dumbIntern.makeForm("Rent contract", "houseOwner");
	}
	catch(std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return (0);
}
