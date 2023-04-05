#include "PmergeMe.hpp"
#include <ctime>
#include <cstdlib>

bool is_str_digit(std::string str)
{
	for (size_t i = 0; i < str.size(); i++)
		if (!isdigit(str[i]))
			return (false);
	return (!str.empty());
}

int main(int argc, char const *argv[])
{
	std::vector<int>	vector;
	std::deque<int>		deque;
	clock_t				vector_time;
	clock_t				deque_time;

	if (argc == 1)
		std::cerr << "Usage: ./pmergeme [integer sequence]" << std::endl;
	else
	{
		for (size_t i = 1; i < (size_t)argc; i++)
		{
			if (!is_str_digit(argv[i]))
			{
				std::cerr << "Error: invalid arguments" << std::endl;
				return (1);
			}
			int n = atoi(argv[i]);
			vector.push_back(n);
			deque.push_back(n);
		}

		std::cout << "Before: ";
		for (size_t i = 0; i < vector.size(); i++)
			std::cout << vector[i] << " ";
		std::cout << std::endl;

		vector_time = clock();
		merge_insert_sort(vector, 0, vector.size() - 1);
		vector_time = clock() - vector_time;
		deque_time = clock();
		merge_insert_sort(deque, 0, deque.size() - 1);
		deque_time = clock() - deque_time;

		std::cout << "After: ";
		for (size_t i = 0; i < vector.size(); i++)
			std::cout << vector[i] << " ";
		std::cout << std::endl;

		std::cout << "Time to process a range of " << vector.size() << " elements with std::vector : " << std::fixed << (double)((double)vector_time / CLOCKS_PER_SEC) << "s" << std::endl;
		std::cout << "Time to process a range of " << deque.size() << " elements with std::deque : " << std::fixed << (double)((double)deque_time / CLOCKS_PER_SEC) << "s" << std::endl;
	}
	return (0);
}
