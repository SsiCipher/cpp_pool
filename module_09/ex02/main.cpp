#include "PmergeMe.hpp"
#include <ctime>
#include <iomanip>
#include <unistd.h>

bool is_str_digit(std::string str)
{
	for (size_t i = 0; i < str.size(); i++)
		if (!isdigit(str[i]))
			return (false);
	return (true);
}

void	sort_vector(std::vector<int> &vec)
{
	
}

int main(int argc, char const *argv[])
{
	std::vector<int>	vector;
	std::list<int>		list;

	if (argc == 1)
		std::cerr << "Error" << std::endl;
	else
	{
		for (size_t i = 1; i < (size_t)argc; i++)
		{
			if (!is_str_digit(argv[i]))
			{
				std::cerr << "Error" << std::endl;
				return (1);
			}
			int n = atoi(argv[i]);
			vector.push_back(n);
			list.push_back(n);
		}

		sort_vector(vector);

		for (size_t i = 0; i < vector.size(); i++)
		{
			std::cout << vector[i] << std::endl;
		}
	}
	return (0);
}
