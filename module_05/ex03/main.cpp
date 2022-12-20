#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	Intern dumbIntern;

	try
	{
		Form *f = dumbIntern.makeForm("robotomy request", "houseOwner");
		std::cout << *f << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return (0);
}
