#include <iostream>

bool    convertToChar(char *)
{
	
}

int main(int argc, char *argv[])
{
	std::string arg;

	if (argc != 2 || *argv[1] == '\0')
		std::cerr << "Usage: ./convert <C++ literal>" << std::endl;
	else
	{
		arg = argv[1];
		std::cout << (char)argv[1][0] << std::endl;
		std::cout << atoi(argv[1]) << std::endl;
		std::cout << atof(argv[1]) << std::endl;
	}
	return (0);
}
