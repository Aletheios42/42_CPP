#include "../Inc/Point.hpp"

void testTriangle(Point const& a, Point const& b, Point const& c, Point const& p) {
    std::cout << "Testing point (" << p.getX() << ", " << p.getY() << ") "
              << "in triangle [(" << a.getX() << ", " << a.getY() << "), "
              << "(" << b.getX() << ", " << b.getY() << "), "
              << "(" << c.getX() << ", " << c.getY() << ")] : ";

    if (bsp(a, b, c, p))
        std::cout << "INSIDE\n";
    else
        std::cout << "OUTSIDE\n";
}

int main() {
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(0.0f, 10.0f);

    Point inside(2.0f, 2.0f);
    Point outside(10.0f, 10.0f);
    Point edge(5.0f, 0.0f);
    Point vertex(0.0f, 0.0f);

    testTriangle(a, b, c, inside);
    testTriangle(a, b, c, outside);
    testTriangle(a, b, c, edge);
    testTriangle(a, b, c, vertex);

    return 0;
}

