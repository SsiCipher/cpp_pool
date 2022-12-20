#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat president("Donald Trump", 148);
		president.decrementGrade();
		president.decrementGrade();
		president.decrementGrade();
		president.decrementGrade();
		president.decrementGrade();
		std::cout << president << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat president("Barack Obama", 24);
		president.incrementGrade();
		president.incrementGrade();
		president.incrementGrade();
		president.incrementGrade();
		std::cout << president << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return (0);
}
