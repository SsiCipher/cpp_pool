#include "Point.hpp"

int main(void)
{
	Point a(1, 2);
	Point b(3, 4);

	a = b;

	std::cout << "x=" << a.getX() << " y=" << b.getY() << std::endl;

	return(0);
}
