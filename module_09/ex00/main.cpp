#include "BitcoinExchange.hpp"

typedef std::map<std::string, double> data_map;

bool is_date_valid(std::string date)
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

void trim_str(std::string &str)
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

bool is_value_valid(std::string value)
{
	double numeric_value;

	numeric_value = atof(value.c_str());
	if (numeric_value == 0 && value[0] != '0')
		return (false);
	return (numeric_value > 0 && numeric_value <= 1000);
}

void read_db(data_map &data)
{
	std::ifstream data_file;
	std::string input_line;
	size_t separator_pos;

	data_file.open("./data/data.csv");
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

void print_exchange_rate(data_map data, std::string input_line)
{
	std::string date, value;
	data_map::iterator closest_date;
	size_t separator_pos;

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
	else if (!is_value_valid(value))
		std::cout << "Error: invalid value" << std::endl;
	else
	{
		if (data.count(date) != 0)
			std::cout << date << " => " << value << " = " << data[date] * atof(value.c_str()) << std::endl;
		else
		{
			closest_date = data.upper_bound(date);
			if (closest_date != data.begin())
				closest_date--;
			std::cout << date << " => " << value << " = " << closest_date->second * atof(value.c_str()) << std::endl;
		}
	}
}

int main(int argc, char *argv[])
{
	data_map data;
	std::ifstream input;
	std::string input_line;

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
				print_exchange_rate(data, input_line);
		}
		input.close();
	}
}
