#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	Bureaucrat president("Donald Trump", 20);
	RobotomyRequestForm form("home");

	try
	{
		form.beSigned(president);
		// president.signForm(form);
		form.execute(president);
		std::cout << president << std::endl;
		std::cout << form << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return (0);
}
