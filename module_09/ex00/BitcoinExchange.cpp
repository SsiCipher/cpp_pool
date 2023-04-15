#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	std::ifstream	data_file;
	std::string		input_line;
	size_t			separator_pos;

	data_file.open("./data/data.csv");
	if (data_file.fail())
		std::cerr << "\033[1;31mError:\033[0m could not open data file." << std::endl;
	else
	{
		std::getline(data_file, input_line);
		while (std::getline(data_file, input_line))
		{
			separator_pos = input_line.find(',');
			if (separator_pos != std::string::npos)
				_data[input_line.substr(0, separator_pos)] = atof(input_line.substr(separator_pos + 1).c_str());
		}
	}
	data_file.close();
}

BitcoinExchange::BitcoinExchange(std::string data_file_name)
{
	std::ifstream	data_file;
	std::string		input_line;
	size_t			separator_pos;

	data_file.open(data_file_name);
	if (data_file.fail())
		std::cerr << "\033[1;31mError:\033[0m could not open data file." << std::endl;
	else
	{
		std::getline(data_file, input_line);
		while (std::getline(data_file, input_line))
		{
			separator_pos = input_line.find(',');
			if (separator_pos != std::string::npos)
				_data[input_line.substr(0, separator_pos)] = atof(input_line.substr(separator_pos + 1).c_str());
		}
	}
	data_file.close();
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
	*this = obj;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	_data = obj._data;
	return (*this);
}

bool	BitcoinExchange::_is_date_valid(std::string date)
{
	int date_parts[3] = {-1, -1, -1};
	size_t i = 0, start = 0, pos = -1;

	while ((pos = date.find('-', pos + 1)) && i < 3)
	{ 
		date_parts[i++] = atoi(date.substr(start, pos - start).c_str());
		start = pos + 1;
		if (pos == std::string::npos)
			break;
	}

	if (
		date_parts[0] == -1 || date_parts[1] == -1 || date_parts[2] == -1
		|| !(date_parts[0] > 0 && date_parts[0] <= 2023)
		|| !(date_parts[1] > 0 && date_parts[1] <= 12)
		|| !(date_parts[2] > 0 && date_parts[2] <= 31)
	)
		return (false);
	return (true);
}

bool	BitcoinExchange::_is_value_valid(std::string value)
{
	double numeric_value;

    for (size_t i = 0; i < value.size(); i++)
        if (!isdigit(value[i]) && value[i] != '.')
            return (false);
    numeric_value = atof(value.c_str());
	return (numeric_value > 0 && numeric_value <= 1000);
}

void	BitcoinExchange::_trim_str(std::string &str)
{
	size_t s, e;

	for (s = 0; str[s] == ' ' || str[s] == '\t'; s++);
	for (e = str.size() - 1; str[e] == ' ' || str[e] == '\t'; e--);
	str.erase(e + 1);
	str.erase(0, s);
}

void	BitcoinExchange::_print_exchange_rate(std::string input_line)
{
	size_t				separator_pos;
	std::string			date, value;
	t_data::iterator	closest_date;

	if (input_line.empty())
	{
		std::cout << "\033[1;31mError:\033[0m empty line" << std::endl;
		return ;
	}
	separator_pos = input_line.find('|');
	date = input_line.substr(0, separator_pos);
	_trim_str(date);
	if (separator_pos != std::string::npos)
	{
		value = input_line.substr(separator_pos + 1);
		_trim_str(value);
	}
	if (!_is_date_valid(date))
		std::cout << "\033[1;31mError:\033[0m invalid date => " << date << std::endl;
	else if (!_is_value_valid(value))
		std::cout << "\033[1;31mError:\033[0m invalid value => " << value << std::endl;
	else
	{
		if (_data.count(date) != 0)
			std::cout << date << " => " << value << " = " << std::fixed << _data[date] * atof(value.c_str()) << std::endl;
		else
		{
			closest_date = _data.upper_bound(date) == _data.begin() ? _data.upper_bound(date) : --_data.upper_bound(date);
			std::cout << date << " => " << value << " = " << std::fixed << closest_date->second * atof(value.c_str()) << std::endl;
		}
	}
}

void	BitcoinExchange::display(std::string input_file_name)
{
	std::ifstream	input;
	std::string		input_line;

	input.open(input_file_name);
	if (input.fail())
		std::cerr << "\033[1;31mError:\033[0m could not open input file." << std::endl;
	else
	{
		std::getline(input, input_line);
		while (std::getline(input, input_line))
			_print_exchange_rate(input_line);
	}
	input.close();
}
