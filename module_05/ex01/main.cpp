#include "Bureaucrat.hpp"

int main(void)
{

	try
	{
		Bureaucrat trump;
		std::cout << trump << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return (0);
}
