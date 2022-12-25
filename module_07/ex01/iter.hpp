#ifndef WHATEVER_H
#define WHATEVER_H

#include <iostream>

template <typename T>
void iter(const T* arr, size_t size, void (*func)(const T&))
{
	for (size_t i = 0; i < size; i++)
		func(arr[i]);
}

template <typename T>
void iter(T* arr, size_t size, void (*func)(T&))
{
	for (size_t i = 0; i < size; i++)
		func(arr[i]);
}

#endif
