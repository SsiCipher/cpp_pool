#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	std::cout << "[BitcoinExchange] Default constructor has been called!" << std::endl;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "[BitcoinExchange] Destructor has been called!" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
	std::cout << "[BitcoinExchange] Copy constructor has been called!" << std::endl;
	*this = obj;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	std::cout << "[BitcoinExchange] Copy assignment operator has been called!" << std::endl;
	_data = obj._data;
	return (*this);
}

void BitcoinExchange::read_data(void)
{
	// std::ifstream data_file;
	// std::string input_line;
	// size_t separator_pos;

	// data_file.open("./data/data.csv");
	// if (data_file.fail())
	// 	std::cerr << "Error: could not open data.csv." << std::endl;
	// else
	// {
	// 	std::getline(data_file, input_line);
	// 	while (std::getline(data_file, input_line))
	// 	{
	// 		separator_pos = input_line.find(',');
	// 		if (separator_pos != std::string::npos)
	// 			this->_data[input_line.substr(0, separator_pos)] = atof(input_line.substr(separator_pos + 1).c_str());
	// 	}
	// }
	// data_file.close();
}
