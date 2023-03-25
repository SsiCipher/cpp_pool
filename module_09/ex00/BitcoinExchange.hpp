#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, double> data;

	public:
		BitcoinExchange(void);
		~BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &obj);
		BitcoinExchange &operator=(const BitcoinExchange &obj);

		
		bool	is_date_valid(std::string date);
		bool	is_value_valid(std::string value);
};

#endif
