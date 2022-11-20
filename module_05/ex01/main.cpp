#include "Bureaucrat.hpp"

int main(void)
{

	Bureaucrat president("Donald Trump", 150);
	Form	lawForm("New Law", 1, 100);

	try
	{
		// lawForm.beSigned(president);
		president.signForm(lawForm);
		std::cout << president << std::endl;
		std::cout << lawForm << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return (0);
}
