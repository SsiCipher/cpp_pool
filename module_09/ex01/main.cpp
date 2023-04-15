#include "RPN.hpp"

int	main(int argc, char const *argv[])
{
	RPN	rpn_calculator;

	if (argc != 2)
		std::cerr << "\033[1;31mError:\033[0m Invalid arguments" << std::endl;
	else
	{
		try
		{
			rpn_calculator.eval(argv[1]);
			rpn_calculator.display_result();
		}
		catch (std::exception &err)
		{
			std::cerr << err.what() << std::endl;
		}
	}
	return (0);
}
