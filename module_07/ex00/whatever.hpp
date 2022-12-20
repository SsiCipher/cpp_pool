#ifndef WHATEVER_H
#define WHATEVER_H

#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<class T> 
const T& min(const T& a, const T& b)
{
	return (a < b ? a : b);
}

template<class T> 
const T& max(const T& a, const T& b)
{
	return (a > b ? a : b);
}

#endif
