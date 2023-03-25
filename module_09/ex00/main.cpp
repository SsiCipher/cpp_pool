#include "BitcoinExchange.hpp"

bool	is_date_valid(std::string date)
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

void	trim_str(std::string &str)
{
	size_t s;
	size_t e;

	for (s = 0; str[s] == ' ' || str[s] == '\t'; s++)
		;
	for (e = str.size() - 1; str[e] == ' ' || str[e] == '\t'; e--)
		;
	str.erase(e + 1);
	str.erase(0, s);
}

bool	is_valid_value(std::string value)
{
	double numeric_value;

	numeric_value = atof(value.c_str());
	if (numeric_value == 0 && value[0] != '0')
		return (false);
	return (numeric_value > 0 && numeric_value <= 1000);
}

void	read_db(std::map<std::string, double> &data)
{
	std::ifstream	data_file;
	std::string		input_line;
	size_t			separator_pos;

	data_file.open("./data.csv");
	if (data_file.fail())
		std::cerr << "Error: could not open data file." << std::endl;
	else
	{
		std::getline(data_file, input_line);
		while (std::getline(data_file, input_line))
		{
			separator_pos = input_line.find(',');
			if (separator_pos != std::string::npos)
				data[input_line.substr(0, separator_pos)] = atof(input_line.substr(separator_pos + 1).c_str());
		}
	}
	data_file.close();
}

int	main(int argc, char *argv[])
{
	std::ifstream	input;
	std::string		input_line;
	size_t			separator_pos;
	std::string	date;
	std::string value;
	std::map<std::string, double> data;
	std::map<std::string, double>::iterator lowest_er;

	if (argc != 2)
		std::cerr << "Error: invalid arguments." << std::endl;
	else
	{
		read_db(data);

		input.open(argv[1]);
		if (input.fail())
			std::cerr << "Error: could not open input file." << std::endl;
		else
		{
			std::getline(input, input_line);
			while (std::getline(input, input_line))
			{
				separator_pos = input_line.find('|');
				date = input_line.substr(0, separator_pos);
				trim_str(date);
				if (separator_pos != std::string::npos)
				{
					value = input_line.substr(separator_pos + 1);
					trim_str(value);
				}
				if (!is_date_valid(date))
					std::cout << "Error: bad input => " << date << std::endl;
				else if (!is_valid_value(value))
					std::cout << "Error: invalid value" << std::endl;
				else
				{
					if (data.count(date) != 0)
						std::cout << date << " => " << value << " = " << data[date] * atof(value.c_str()) << std::endl;
					else
					{
						lowest_er = data.upper_bound(date);
						std::cout << date << " => " << value << " = " << (--lowest_er)->second * atof(value.c_str()) << std::endl;
					}
				}
			}
		}
		input.close();
	}
}