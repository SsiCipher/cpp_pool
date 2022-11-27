#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main(void)
{
	Point a(0, 0);
	Point b(20, 0);
	Point c(10, 30);
	Point p(10, 150);

	std::cout << bsp(a, b, c, p) << std::endl;
	return(0);
}
