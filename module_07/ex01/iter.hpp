#ifndef WHATEVER_H
#define WHATEVER_H

#include <iostream>

template <typename T, typename F>
void iter(T* arr, unsigned int size, F func)
{
	for (unsigned int i = 0; i < size; i++)
	{
		func(arr[i]);
	}
}

#endif
