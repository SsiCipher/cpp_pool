#include <iostream>

enum e_types{CHAR, INT, FLOAT, DOUBLE, INVALID};

bool    isChar(const std::string &str)
{
	return (str.length() == 1);
}

bool    isInt(const std::string &str)
{
	int i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	for (; str[i]; i++)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}

bool isFloat(const std::string &str)
{
	size_t	i = 0;
	bool		decimalPoint = false;
	size_t	decimalPointIndex =  str.find('.');

	if (str == "-inff" || str == "+inff" || str == "nanf")
		return (true);
	if (str[i] == '+' || str[i] == '-')
		i++;
	for (; str[i]; i++)
	{
		if (str[i] == '.' && !decimalPoint)
			decimalPoint = true;
		else if (str[i] == '.' && decimalPoint)
			return (false);
		else if ((i+1 == str.size() && str[i] != 'f') || (!std::isdigit(str[i]) && i+1 != str.size()))
			return (false);
	}
	return (decimalPoint && decimalPointIndex && std::isdigit(str[decimalPointIndex+1]));
}

bool isDouble(const std::string &str)
{
	size_t	i = 0;
	bool		decimalPoint = false;
	size_t	decimalPointIndex =  str.find('.');

	if (str == "-inf" || str == "+inf" || str == "nan")
		return (true);
	if (str[i] == '+' || str[i] == '-')
		i++;
	for (; str[i]; i++)
	{
		if (str[i] == '.' && !decimalPoint)
			decimalPoint = true;
		else if (str[i] == '.' && decimalPoint)
			return (false);
		else if (!std::isdigit(str[i]))
			return (false);
	}
	return (decimalPoint && decimalPointIndex && std::isdigit(str[decimalPointIndex+1]));
}

e_types getDataType(const std::string &data)
{
	if (isInt(data))
		return (INT);
	else if (isChar(data))
		return (CHAR);
	else if (isFloat(data))
		return (FLOAT);
	else if (isDouble(data))
		return (DOUBLE);
	else
		return (INVALID);
}

int main(int argc, const char *argv[])
{
	e_types dataType;

	if (argc != 2 || *argv[1] == '\0')
		std::cerr << "Usage: ./convert <C++ literal>" << std::endl;
	else
	{
		dataType = getDataType(argv[1]);
		std::cout << dataType << std::endl;
	}
	return (0);
}
