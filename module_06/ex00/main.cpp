#include <iostream>

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

int main(int argc, const char *argv[])
{
	if (argc != 2 || *argv[1] == '\0')
		std::cerr << "Usage: ./convert <C++ literal>" << std::endl;
	else
	{
		if (isChar(argv[1]))
			std::cout << "it's an CHAR" << std::endl;
		else if (isInt(argv[1]))
			std::cout << "it's an INT" << std::endl;
		else if (isFloat(argv[1]))
			std::cout << "it's an FLOAT" << std::endl;
		else if (isDouble(argv[1]))
			std::cout << "it's an DOUBLE" << std::endl;
		else
			std::cout << "it's INVALID" << std::endl;
	}
	return (0);
}
