#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat			president("Barack Obama", 1);
		RobotomyRequestForm	form("human");
		// form.beSigned(president);
		president.executeForm(form);
		// form.execute(president);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
