#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	BitcoinExchange	be;

	if (argc != 2)
		std::cerr << "\033[1;31mError:\033[0m invalid arguments." << std::endl;
	else
		be.display(argv[1]);
}
