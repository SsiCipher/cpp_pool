#include "iter.hpp"

int	printDouble(int n)
{
	std::cout << n * 2 << std::endl;
	return (n);
}

int main(void)
{
	int arr[] = {1, 2, 3};

	iter(arr, 3, printDouble);

	return (0);
}
