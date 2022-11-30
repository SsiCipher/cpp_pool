#include "Point.hpp"

Fixed   triangle_area(Point const a, Point const b, Point const c)
{
    Fixed tri_area;

    tri_area = std::abs(
        (
            (
                a.getX() * (b.getY() - c.getY()) +
                b.getX() * (c.getY() - a.getY()) +
                c.getX() * (a.getY() - b.getY())
            ) / Fixed(2.0f)
        ).toFloat()
    );
    return (tri_area);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed baseTriangleArea = triangle_area(a, b, c);
    Fixed subTriangleArea1 = triangle_area(point, b, c);
    Fixed subTriangleArea2 = triangle_area(a, point, c);
    Fixed subTriangleArea3 = triangle_area(a, b, point);
    if (subTriangleArea1 == 0 || subTriangleArea2 == 0 || subTriangleArea3 == 0)
        return (false);
    return (baseTriangleArea == subTriangleArea1 + subTriangleArea2 + subTriangleArea3);
}
