#include "BitcoinExchange.hpp"

bool is_date_valid(std::string date)
{
	std::string::size_type start = 0;
	std::string::size_type pos = -1;
	std::vector<int> dateParts;

	while ((pos = date.find('-', pos + 1)))
	{
		dateParts.push_back(atoi(date.substr(start, pos - start).c_str()));
		start = pos + 1;
		if (pos == std::string::npos)
			break;
	}

	if (dateParts.size() != 3 || !(dateParts[0] > 0 && dateParts[0] <= 2023) || !(dateParts[1] > 0 && dateParts[1] <= 12) || !(dateParts[2] > 0 && dateParts[2] <= 31))
		return (false);
	return (true);
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
