#include <iostream>
#include <vector>

using namespace std;

void printArray(std::vector<int> &array)
{
	for (int i = 0; i < array.size(); i++)
		cout << array[i] << " ";
	cout << endl;
}

void insertionSort(std::vector<int> &array)
{
	for (int i = 1; i < array.size(); i++)
	{
		int j;
		int tmp = array[i];

		for (j = i - 1; tmp < array[j] && j >= 0; j--)
			array[j + 1] = array[j];
		array[j + 1] = tmp;
	}
}

int main()
{
	std::vector<int> vec;
	
	vec.push_back(9); 
	vec.push_back(5); 
	vec.push_back(1); 
	vec.push_back(4); 
	vec.push_back(3);

	insertionSort(vec);

	cout << "Sorted array in ascending order:\n";

	printArray(vec);

	return (0);
}
