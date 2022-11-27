#include "Fixed.hpp"

int main(void)
{
	Fixed a(1.65f);
	Fixed b(1.65f);

	std::cout << (a > b) << std::endl;
	return (0);
}
