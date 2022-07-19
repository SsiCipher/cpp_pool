#include <iostream>

int main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 0; i < argc - 1; i++)
		{
			for (int j = 0; argv[i + 1][j]; j++)
				std::cout << (char)toupper(argv[i + 1][j]);
		}
		std::cout << std::endl;
	}

	return (0);
}
