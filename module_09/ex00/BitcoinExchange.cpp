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
	(void)obj;
	return (*this);
}
