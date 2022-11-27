#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main(void)
{
	Point a(0, 0);
	Point b(20, 0);
	Point c(10, 30);
	Point p1(10, 150);
	Point p2(10, 15);

	std::cout << "Test #1: " << bsp(a, b, c, p1) << std::endl;
	std::cout << "Test #2: " << bsp(a, b, c, p2) << std::endl;

	return(0);
}
