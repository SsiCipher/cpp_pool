#ifndef EASYFIND_H
# define EASYFIND_H

# include <iostream>
# include <algorithm>

template <typename T>
void	easyfind(T &container, int n)
{
	typename T::iterator item = std::find(container.begin(), container.end(), n);

	if (item != container.end())
		std::cout << "✔ Element " << n << " was found in the container" << std::endl;
	else
		throw std::out_of_range("❌ Element was not found in the container");
}

#endif
