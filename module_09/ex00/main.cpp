#include "BitcoinExchange.hpp"

bool	check_date(std::string &date_str)
{
	std::vector 
	date_str.
}

int main(int argc, char *argv[])
{
	std::string input_line;
	std::ifstream input;

	if (argc != 2)
		std::cerr << "Error: could not open file." << std::endl;
	else
	{
		input.open(argv[1]);
		if (input.fail())
			std::cerr << "Error: could not open file." << std::endl;
		else
		{
			std::getline(input, input_line);
			while (std::getline(input, input_line))
			{
				std::cout << input_line << std::endl;
			}
		}
		input.close();
	}
}
