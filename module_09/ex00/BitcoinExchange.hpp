#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>

class BitcoinExchange
{
	public:
		typedef std::map<std::string, double>	t_data;

	private:
		t_data	_data;

		bool	_is_date_valid(std::string date);
		bool	_is_value_valid(std::string value);
		void	_trim_str(std::string &str);
		void	_print_exchange_rate(std::string input_line);

	public:
		BitcoinExchange(void);
		BitcoinExchange(std::string data_file_name);
		~BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &obj);
		BitcoinExchange &operator=(const BitcoinExchange &obj);

		void	display(std::string input_file_name);
};

#endif
