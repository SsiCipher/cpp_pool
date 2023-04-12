#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	BitcoinExchange	be;

	if (argc != 2)
		std::cerr << "Error: invalid arguments." << std::endl;
	else
		be.display(argv[1]);
}
