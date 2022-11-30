#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main(void)
{
	Point a(0, 0);
	Point b(20, 0);
	Point c(10, 30);

	Point p1(10, 0);
	std::cout << "Test (on edge) #1: " << bsp(a, b, c, p1) << std::endl;
	Point p2(10, 20);
	std::cout << "Test (inside triangle) #2: " << bsp(a, b, c, p2) << std::endl;
	Point p3(10, 25);
	std::cout << "Test (inside triangle) #3: " << bsp(a, b, c, p3) << std::endl;
	Point p4(10, 30);
	std::cout << "Test (a vertex) #4: " << bsp(a, b, c, p4) << std::endl;

	return(0);
}
