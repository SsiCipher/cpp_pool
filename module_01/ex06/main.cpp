#include "Harl.hpp"

int main(int argc, char *argv[])
{
	Harl h;

	if (argc != 2)
		std::cout << "ERROR: not enough arguments\n";
	else
	{
		h.complain(argv[1]);
	}

	return (0);
}
