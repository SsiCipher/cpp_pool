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

template <typename T>
void	print_container(std::string label, T &container)
{
	typename T::iterator it;

	std::cout << label << ": ";
	for (it = container.begin(); it != container.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	sort_containers(std::vector<int> &vector, clock_t &vector_time, std::deque<int> &deque, clock_t &deque_time)
{
	vector_time = clock();
	merge_insert_sort(vector, 0, vector.size() - 1);
	vector_time = clock() - vector_time;
	deque_time = clock();
	merge_insert_sort(deque, 0, deque.size() - 1);
	deque_time = clock() - deque_time;
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
				std::cerr << "\033[1;31mError:\033[0m invalid arguments" << std::endl;
				return (1);
			}
			int n = atoi(argv[i]);
			vector.push_back(n);
			deque.push_back(n);
		}

		print_container("Before", vector);

		sort_containers(vector, vector_time, deque, deque_time);

		print_container("After", vector);

		std::cout << "Time to process a range of " << vector.size() << " elements with std::vector : " << std::fixed << (double)((double)vector_time / CLOCKS_PER_SEC) << "s" << std::endl;
		std::cout << "Time to process a range of " << deque.size() << " elements with std::deque : " << std::fixed << (double)((double)deque_time / CLOCKS_PER_SEC) << "s" << std::endl;
	}
	return (0);
}
