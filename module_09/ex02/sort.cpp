#include <iostream>
#include <vector>

// void insertion_sort(double *array, int l, int r)
// {
// 	for (int i = l; i <= r; i++)
// 	{
// 		double tmp = array[i];
// 		int j = i;
// 		while ((j > l) && (array[j - 1] > tmp))
// 		{
// 			array[j] = array[j - 1];
// 			j--;
// 		}
// 		array[j] = tmp;
// 	}
// }

// void merge(double *arr, double *temp, int l, int m, int r)
// {
// 	int i = l;
// 	int j = m + 1;
// 	int k = l;
// 	while ((i <= m) && (j <= r))
// 	{
// 		if (arr[i] < arr[j])
// 		{
// 			temp[k] = arr[i];
// 			i++;
// 		}
// 		else
// 		{
// 			temp[k] = arr[j];
// 			j++;
// 		}
// 		k++;
// 	}

// 	for (; j <= r; j++, k++)
// 		temp[k] = arr[j];

// 	for (; i <= m; i++, k++)
// 		temp[k] = arr[i];

// 	for (i = l; i <= r; i++)
// 		arr[i] = temp[i];
// }

// void mergesort(double *arr, double *temp, int l, int r, int threshold)
// {
// 	if (l < r)
// 	{
// 		if ((r - l) <= threshold)
// 			insertion_sort(arr, l, r);
// 		else
// 		{
// 			int m = (l + r) / 2;
// 			mergesort(arr, temp, l, m, threshold);
// 			mergesort(arr, temp, m + 1, r, threshold);
// 			merge(arr, temp, l, m, r);
// 		}
// 	}
// }

void	msort(std::vector<int> &arr)
{
	
}

int main()
{
	std::vector<int> array;

	for (int i = 0; i < 20; i++)
	{
		array.push_back(rand() % 20 + 1);
		std::cout << array[i] << ", ";
	}
	std::cout << std::endl;

	msort(array);
 
	for (int i = 0; i < 20; i++)
		std::cout << array[i] << ", ";

	std::cout << std::endl;

	return (0);
}
