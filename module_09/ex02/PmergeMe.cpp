#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
	std::cout << "[PmergeMe] Default constructor has been called!" << std::endl;
}

PmergeMe::~PmergeMe()
{
	std::cout << "[PmergeMe] Destructor has been called!" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
	std::cout << "[PmergeMe] Copy constructor has been called!" << std::endl;
	*this = obj;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
	std::cout << "[PmergeMe] Copy assignment operator has been called!" << std::endl;
	if (this != &obj)
	{
	}
	return (*this);
}
