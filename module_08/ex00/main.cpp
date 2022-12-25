#include "easyfind.hpp"
#include <vector>

int main()
{
	std::vector<int> v;

	v.push_back(4);
	v.push_back(8);
	v.push_back(12);
	v.push_back(2);

	try
	{
		easyfind(v, 22);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
