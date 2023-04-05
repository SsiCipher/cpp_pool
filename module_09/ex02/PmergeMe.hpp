#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>

class PmergeMe
{
private:
public:
	PmergeMe(void);
	~PmergeMe(void);
	PmergeMe(const PmergeMe &obj);
	PmergeMe &operator=(const PmergeMe &obj);
};

void merge_insert_sort(std::vector<int> &arr, size_t l, size_t r);
void merge_insert_sort(std::deque<int> &arr, size_t l, size_t r);

#endif
