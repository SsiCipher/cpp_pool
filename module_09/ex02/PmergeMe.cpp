#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
	*this = obj;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
	(void)obj;
	return (*this);
}

void insertion_sort(std::vector<int> &array, size_t l, size_t r)
{
	for (size_t i = l; i <= r; i++)
	{
		int tmp = array[i];
		size_t j = i;
		while ((j > l) && (array[j - 1] > tmp))
		{
			array[j] = array[j - 1];
			j--;
		}
		array[j] = tmp;
	}
}

void merge_array(std::vector<int> &array, size_t l, size_t m, size_t r)
{
	size_t i, j, k = l, nl = m - l + 1, nr = r - m;
	int larr[nl], rarr[nr];

	for (i = 0; i < nl; i++)
		larr[i] = array[l + i];
	for (j = 0; j < nr; j++)
		rarr[j] = array[m + 1 + j];

	i = 0;
	j = 0;
	while (i < nl && j < nr)
	{
		if (larr[i] <= rarr[j])
			array[k] = larr[i++];
		else
			array[k] = rarr[j++];
		k++;
	}

	while (i < nl)
		array[k++] = larr[i++];
	while (j < nr)
		array[k++] = rarr[j++];
}

void merge_insert_sort(std::vector<int> &arr, size_t l, size_t r)
{
	if (l < r)
	{
		if ((r - l) <= 10)
			insertion_sort(arr, l, r);
		else
		{
			int m = (l + r) / 2;
			merge_insert_sort(arr, l, m);
			merge_insert_sort(arr, m + 1, r);
			merge_array(arr, l, m, r);
		}
	}
}

void insertion_sort(std::deque<int> &array, size_t l, size_t r)
{
	for (size_t i = l; i <= r; i++)
	{
		int tmp = array[i];
		size_t j = i;
		while ((j > l) && (array[j - 1] > tmp))
		{
			array[j] = array[j - 1];
			j--;
		}
		array[j] = tmp;
	}
}

void merge_array(std::deque<int> &array, size_t l, size_t m, size_t r)
{
	size_t i, j, k = l, nl = m - l + 1, nr = r - m;
	int larr[nl], rarr[nr];

	for (i = 0; i < nl; i++)
		larr[i] = array[l + i];
	for (j = 0; j < nr; j++)
		rarr[j] = array[m + 1 + j];

	i = 0;
	j = 0;
	while (i < nl && j < nr)
	{
		if (larr[i] <= rarr[j])
			array[k] = larr[i++];
		else
			array[k] = rarr[j++];
		k++;
	}

	while (i < nl)
		array[k++] = larr[i++];
	while (j < nr)
		array[k++] = rarr[j++];
}

void merge_insert_sort(std::deque<int> &arr, size_t l, size_t r)
{
	if (l < r)
	{
		if ((r - l) <= 10)
			insertion_sort(arr, l, r);
		else
		{
			int m = (l + r) / 2;
			merge_insert_sort(arr, l, m);
			merge_insert_sort(arr, m + 1, r);
			merge_array(arr, l, m, r);
		}
	}
}
